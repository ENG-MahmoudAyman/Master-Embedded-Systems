/*
 * Scheduler.h
 *
 *  Created on: May 8, 2024
 *      Author: engma
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "CortexM3&4_OS_Porting.h"
#include <string.h>
#include "MY_RTOS_Config.h"




#define MY_RTOS_Config_Task(TaskRef, Name, priority, Callback, StackSize)	    strcpy(TaskRef.TaskName, Name);\
																				TaskRef.Priority = priority;\
																				TaskRef.p_TaskEntry = Callback;\
																				TaskRef.Stack_Size = StackSize

#define MY_RTOS_Config_Mutex(MutexRef, Name, PayloadSize, P_to_payload)         strcpy(MutexRef.Mutex_Name,Name);\
																				MutexRef.Current_User = NULL;\
																				MutexRef.Payload_Size = PayloadSize;\
																				MutexRef.Ppayload = P_to_payload;

typedef enum{
	NO_ERROR,
	Queue_FIFO_init_ERROR,
	Task_Exceeded_StackSize_ERROR,
	Mutex_Max_Waiting

}MY_RTOS_ERROR_ID;

typedef struct{
	uint32 Stack_Size;
	uint8 Priority;
	void (*p_TaskEntry)(void);//Pointer to Task C Function
	uint8 AutoStart;
	uint32 _S_PSP_Task;//Not Entered by User
	uint32 _E_PSP_Task;//Not Entered by User
	uint32* Current_PSP;//Not Entered by User
	char TaskName[30];
	enum{
		Suspend,
		Running,
		Waiting,
		Ready
	}TaskState;//Not Entered by User
	struct{
		enum{
			Disable_Waiting,
			Enable_Waiting
		}Blocking;
		uint32 Ticks;
	}TimingWaiting;

}Task_Ref;

#ifdef MutexUsed

typedef struct{
	uint8* Ppayload;
	uint32 Payload_Size;
	Task_Ref* Current_User;
	char Mutex_Name[30];
	Task_Ref* Next_Users[MutexMaxWaiting];
}Mutex_Ref;

#endif

void OS_SVC(int* StackFramePointer);
MY_RTOS_ERROR_ID MY_RTOS_init(void);
MY_RTOS_ERROR_ID MY_RTOS_Create_Task(Task_Ref* Tref);
void MY_RTOS_Activate_Task(Task_Ref* Tref);
void MY_RTOS_Terminate_Task(Task_Ref* Tref);
void MY_RTOS_StartOS();
void MY_RTOS_Task_Wait(uint32 Ticks , Task_Ref* Tref);
void MY_RTOS_Task_StopWait(Task_Ref* Tref);
void MY_RTOS_Task_ContinueWait(Task_Ref* Tref);
MY_RTOS_ERROR_ID MY_RTOS_Acquire_Mutex(Mutex_Ref* Mref ,Task_Ref* Tref);
void MY_RTOS_Release_Mutex(Mutex_Ref* Mref);

#endif /* INC_SCHEDULER_H_ */
