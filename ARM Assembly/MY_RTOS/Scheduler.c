/*
 * Scheduler.c
 *
 *  Created on: May 8, 2024
 *      Author: engma
 */



#include "Scheduler.h"
#include "MY_RTOS_FIFO.h"


void MY_RTOS_IDLE_TASK(void);
void MY_RTOS_Create_TaskStack(Task_Ref* Tref);
void MY_RTOS_Create_MainStack(void);
void BubbleSort(void);
void MY_RTOS_Update_SchedulerTable(void);
void DecideNext(void);

typedef enum{
	SVC_TerminateTask,
	SVC_ActivateTask,
	SVC_TaskWaitingTime
}SVC_ID;

void OS_SVC_Set(SVC_ID ID);



struct{
	Task_Ref* OSTasks[100];
	uint32 _S_MSP_Task;
	uint32 _E_MSP_Task;
	uint32 PSP_Task_Locator;
	uint32 No_Active_Tasks;
	Task_Ref* CurrentTask;
	Task_Ref* NextTask;
	enum{
		OS_Suspend,
		OS_Running
	}OS_Mode_ID;
}OS_Control;


FIFO_Buf_t Ready_Queue;
Task_Ref* Ready_Queue_FIFO[TasksMaxNumber];
Task_Ref MY_RTOS_IDLE_Task;


void MY_RTOS_Create_MainStack(void){
	OS_Control._S_MSP_Task = (uint32)(&_estack);
	OS_Control._E_MSP_Task = (OS_Control._S_MSP_Task - MainStack_Size);
	OS_Control.PSP_Task_Locator = (OS_Control._E_MSP_Task - 8);

}

void MY_RTOS_Create_TaskStack(Task_Ref* Tref){
	/*Task Frame
	 * Manual:
	 * R4,R5,R6,R7,R8,R9,R10,R11
	 * Automatic:
	 * R0,R1,R2,R3,R12,LR,PC,xPSR */

	// Virtual Memory Stack Reservation

	Tref->Current_PSP = (uint32*)(Tref->_S_PSP_Task) ;
	Tref->Current_PSP-- ;
	*(Tref->Current_PSP) = 0x01000000;         //DUMMY_XPSR should T =1 to avoid BUS fault;//0x01000000
	Tref->Current_PSP-- ;
	*(Tref->Current_PSP) = (unsigned int)Tref->p_TaskEntry ; //PC
	Tref->Current_PSP-- ; //LR = 0xFFFFFFFD (EXC_RETURN)Return to thread with PSP
	*(Tref->Current_PSP)  = 0xFFFFFFFD ;

	for (int  j=0 ; j< 13 ; j++ )
	{
		Tref->Current_PSP-- ;
		*(Tref->Current_PSP)  = 0 ;
	}

}


MY_RTOS_ERROR_ID MY_RTOS_init(void){

	MY_RTOS_ERROR_ID error = NO_ERROR;

	//Update OS Mode (OS suspend)
	OS_Control.OS_Mode_ID = OS_Suspend;
	//Specify OS_MSP
	MY_RTOS_Create_MainStack();
	//Create OS Ready Queue
	if(FIFO_Init(&Ready_Queue, Ready_Queue_FIFO, TasksMaxNumber)!= FIFO_No_Error){
		error += Queue_FIFO_init_ERROR;
	}

	//Configure IDLE Task
	strcpy(MY_RTOS_IDLE_Task.TaskName, "IDLE_Task");
	MY_RTOS_IDLE_Task.Priority = 255;
	MY_RTOS_IDLE_Task.p_TaskEntry = MY_RTOS_IDLE_TASK;
	MY_RTOS_IDLE_Task.Stack_Size = 200;
	error += MY_RTOS_Create_Task(&MY_RTOS_IDLE_Task);

	return error;
}

void MY_RTOS_StartOS(){
	OS_Control.OS_Mode_ID = OS_Running;
	//Default Task
	OS_Control.CurrentTask = &MY_RTOS_IDLE_Task;
	MY_RTOS_Activate_Task(&MY_RTOS_IDLE_Task);
	//Start Ticker
	StartTicker();
	OS_SET_PSP(OS_Control.CurrentTask->Current_PSP);
	OS_SWITCH_SP_to_PSP;
	OS_SWITCH_CPU_access_level_to_unprivileged;
	MY_RTOS_IDLE_Task.p_TaskEntry();

}

MY_RTOS_ERROR_ID MY_RTOS_Create_Task(Task_Ref* Tref){
	MY_RTOS_ERROR_ID Error = NO_ERROR;

	//check stack size exceed PSP
	Tref->_S_PSP_Task = OS_Control.PSP_Task_Locator;
	Tref->_E_PSP_Task = (Tref->_S_PSP_Task - Tref->Stack_Size);
	if(Tref->_E_PSP_Task < (uint32)(&(_eheap))){
		return Task_Exceeded_StackSize_ERROR;
	}
	OS_Control.PSP_Task_Locator = (Tref->_E_PSP_Task  - 8);

	MY_RTOS_Create_TaskStack(Tref);

	OS_Control.OSTasks[OS_Control.No_Active_Tasks] = Tref;
	OS_Control.No_Active_Tasks++;
	Tref->TimingWaiting.Blocking = Disable_Waiting;
	Tref->TaskState = Suspend;

	return Error;
}

void MY_RTOS_Activate_Task(Task_Ref* Tref){
	Tref->TaskState = Waiting;
	OS_SVC_Set(SVC_ActivateTask);
}
void MY_RTOS_Terminate_Task(Task_Ref* Tref){
	Tref->TaskState = Suspend;
	OS_SVC_Set(SVC_TerminateTask);
}

void MY_RTOS_Task_Wait(uint32 Ticks , Task_Ref* Tref){
	Tref->TimingWaiting.Blocking = Enable_Waiting;
	Tref->TimingWaiting.Ticks = (Ticks + 1);
	Tref->TaskState = Suspend;
	OS_SVC_Set(SVC_TerminateTask);
}

void MY_RTOS_Task_StopWait(Task_Ref* Tref){
	Tref->TimingWaiting.Blocking = Disable_Waiting;
	Tref->TaskState = Waiting;
	OS_SVC_Set(SVC_ActivateTask);
}

void MY_RTOS_Task_ContinueWait(Task_Ref* Tref){
	Tref->TimingWaiting.Blocking = Enable_Waiting;
	Tref->TaskState = Suspend;
	OS_SVC_Set(SVC_TerminateTask);
}

uint8 IdleTaskIndic;

void MY_RTOS_IDLE_TASK(void){
	while(1){
		__asm("WFE");
		IdleTaskIndic ^= 1;
	}

}


MY_RTOS_ERROR_ID MY_RTOS_Acquire_Mutex(Mutex_Ref* Mref ,Task_Ref* Tref){
	if(Mref->Current_User == NULL)/*Free*/{
		Mref->Current_User = Tref;
		return NO_ERROR;
	}
	else{
		if(Mref->Current_User == Tref){
			return NO_ERROR;
		}
		uint8 i = 0;
		for(i = 0; i < MutexMaxWaiting; i++){
			if(Mref->Next_Users[i] == NULL)/*Reserve*/{
				Mref->Next_Users[i] = Tref;
				Tref->TaskState = Suspend;
				OS_SVC_Set(SVC_TerminateTask);
				return NO_ERROR;
			}
		}
		return Mutex_Max_Waiting;
	}

}
void MY_RTOS_Release_Mutex(Mutex_Ref* Mref){

	if(Mref->Current_User != NULL)/*Taken*/{
		Mref->Current_User = Mref->Next_Users[0];
		uint8 i = 0;
		for(i = 0; i < MutexMaxWaiting-1; i++){
			if(Mref->Next_Users[i] != NULL)/*Reserve*/{
				Mref->Next_Users[i] = Mref->Next_Users[i+1];
			}
			else{
				break;
			}
		}
		Mref->Current_User->TaskState = Waiting;
		OS_SVC_Set(SVC_ActivateTask);
	}

}

/*----- Handler Section ---- */

__attribute ((naked)) void PendSV_Handler(){
	//Save Current Task Context
	OS_GET_PSP(OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP--;
	OS_SaveContext(R4 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP--;
	OS_SaveContext(R5 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP--;
	OS_SaveContext(R6 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP--;
	OS_SaveContext(R7 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP--;
	OS_SaveContext(R8 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP--;
	OS_SaveContext(R9 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP--;
	OS_SaveContext(R10 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP--;
	OS_SaveContext(R11 , OS_Control.CurrentTask->Current_PSP);

	//Restore Next Task Context
	if (OS_Control.NextTask != NULL){
	OS_Control.CurrentTask = OS_Control.NextTask ;
	OS_Control.NextTask = NULL ;
	}

	OS_RestoreContext(R11 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP++;
	OS_RestoreContext(R10 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP++;
	OS_RestoreContext(R9 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP++;
	OS_RestoreContext(R8 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP++;
	OS_RestoreContext(R7 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP++;
	OS_RestoreContext(R6 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP++;
	OS_RestoreContext(R5 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP++;
	OS_RestoreContext(R4 , OS_Control.CurrentTask->Current_PSP);
	OS_Control.CurrentTask->Current_PSP++;

	//Update PSP
	OS_SET_PSP(OS_Control.CurrentTask->Current_PSP);
	__asm volatile ("BX LR");



}

void DecideNext(void){
	//If Queue is Empty & Current TasK != Suspend
	if((Ready_Queue.count == 0) && (OS_Control.CurrentTask->TaskState != Suspend)){
		OS_Control.CurrentTask->TaskState = Running;
		//add Current Task to Ready Queue (Round Robin)
		FIFO_Enqueue(&Ready_Queue, OS_Control.CurrentTask);
		OS_Control.NextTask = OS_Control.CurrentTask;
	}
	else{
		FIFO_Dequeue(&Ready_Queue, &OS_Control.NextTask);
		OS_Control.NextTask->TaskState = Running;
		//update Ready queue (to keep Round Robin)
		if((OS_Control.CurrentTask->Priority == OS_Control.NextTask->Priority)&&(OS_Control.CurrentTask->TaskState != Suspend)){
			FIFO_Enqueue(&Ready_Queue, OS_Control.CurrentTask);
			OS_Control.CurrentTask->TaskState = Ready;
		}
	}
}


void OS_SVC(int* StackFramePointer){

	SVC_ID ID;

	ID = (*(uint8*)(((uint8*)StackFramePointer[6])-2));

	switch(ID){
	case SVC_TerminateTask: //Terminate Task
	case SVC_ActivateTask: //Activate Task
		//Update SchTable
		MY_RTOS_Update_SchedulerTable();
		//OS is in Running State
		if(OS_Control.OS_Mode_ID == OS_Running){
			if (strcmp(OS_Control.CurrentTask->TaskName,"IDLE_Task") != 0){
				//Decide Next
				DecideNext();
				//Trigger OS_PendSV
				Trigger_OS_PendSV();
			}
		}
		break;
	case SVC_TaskWaitingTime:
		MY_RTOS_Update_SchedulerTable();

		break;
	}

}

void MY_RTOS_Update_SchedulerTable(void){

	//Bubble sort SchTable Higher ---> Lower Priority
	BubbleSort();
	//Free Ready Queue
	Task_Ref* Temp = NULL;
	while(FIFO_Dequeue(&Ready_Queue, &Temp /* Pointer to Pointer */)!= FIFO_Empty);
	//Update Ready Queue
	uint8 i = 0 ;
	for( i = 0 ; i < OS_Control.No_Active_Tasks ; i++){

		if (OS_Control.OSTasks[i]->TaskState != Suspend){
			if ( OS_Control.OSTasks[i]->Priority != OS_Control.OSTasks[i+1]->Priority ){
				FIFO_Enqueue(&Ready_Queue, OS_Control.OSTasks[i]);
				OS_Control.OSTasks[i]->TaskState = Ready;
				break;
			}
			else if(OS_Control.OSTasks[i]->Priority == OS_Control.OSTasks[i+1]->Priority){
				FIFO_Enqueue(&Ready_Queue, OS_Control.OSTasks[i]);
				OS_Control.OSTasks[i]->TaskState = Ready;
			}
			else if(OS_Control.OSTasks[i] > OS_Control.OSTasks[i+1]){
				break;
			}
		}
	}

}

void MY_RTOS_Update_TaskingTime(void){
	uint8 i = 0;
	for(i = 0 ; i < OS_Control.No_Active_Tasks ; i++){
		if(OS_Control.OSTasks[i]->TimingWaiting.Blocking == Enable_Waiting){
			OS_Control.OSTasks[i]->TimingWaiting.Ticks--;
			if(OS_Control.OSTasks[i]->TimingWaiting.Ticks == 0){
				OS_Control.OSTasks[i]->TimingWaiting.Blocking = Disable_Waiting;
				OS_Control.OSTasks[i]->TaskState = Waiting;
				OS_SVC_Set(SVC_TaskWaitingTime);
			}
		}
	}
}

void OS_SVC_Set(SVC_ID ID){

	switch(ID){
	case SVC_TerminateTask: //Terminate Task
		__asm("SVC #0x0");
		break;
	case SVC_ActivateTask: //Activate Task
		__asm("SVC #0x1");
		break;
	case SVC_TaskWaitingTime:
		__asm("SVC #0x2");//mult
		break;

	}

}

void BubbleSort(void){

	uint8 i,j, n = OS_Control.No_Active_Tasks;
	Task_Ref* Temp;

	for(i=0 ; i < n-1 ; i++){
		for(j= 0; j < n-i-1 ; j++){
			if(OS_Control.OSTasks[j]->Priority > OS_Control.OSTasks[j+1]->Priority){
				Temp = OS_Control.OSTasks[j];
				OS_Control.OSTasks[j] = OS_Control.OSTasks[j+1];
				OS_Control.OSTasks[j+1] = Temp;
			}
		}
	}

}
