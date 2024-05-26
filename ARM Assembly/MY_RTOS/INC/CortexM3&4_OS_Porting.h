/*
 * CortexM3&4_OS_Porting.h
 *
 *  Created on: May 8, 2024
 *      Author: engma
 */

#ifndef INC_CORTEXM3_4_OS_PORTING_H_
#define INC_CORTEXM3_4_OS_PORTING_H_

#include "platform_Types.h"

#include "core_cm3.h"

extern int _estack ;
extern int _eheap  ;

#define MainStack_Size 3072 //3KB

#define OS_SET_PSP(add)              __asm volatile ("MOV R0,%[in] \n\t""MSR PSP,R0" : :[in]"r"(add))
#define OS_GET_PSP(take)              __asm volatile ("MRS R0, PSP \n\t" "MOV %[out],R0" : [out]"=r"(take))
#define OS_SWITCH_SP_to_PSP          __asm volatile ("MRS R0,CONTROL \n\t""ORR R0,R0, #0x02 \n\t""MSR CONTROL,R0")
#define OS_SWITCH_SP_to_MSP          __asm volatile ("MRS R0,CONTROL \n\t""AND R0,R0, #0x05 \n\t""MSR CONTROL,R0")
#define OS_Generate_Exception        __asm volatile ("SVC #0x03")
#define OS_SWITCH_CPU_access_level_to_privileged  \
	    __asm(" MRS R0, CONTROL \n\t"" LSR R0,R0, #0x1 \n\t"" LSL R0,R0, #0x1 \n\t"" MSR CONTROL, R0 " );\

#define OS_SWITCH_CPU_access_level_to_unprivileged  \
		__asm(" MRS R0, CONTROL \n\t"" ORR R0,R0, #0x1 \n\t"" MSR CONTROL, R0" );\

#define OS_SaveContext(Register , PSP_Pointer)     __asm volatile("MOV %[PSP], " #Register : [PSP] "=r" (*(PSP_Pointer)))
#define OS_RestoreContext(Register , PSP_Pointer)  __asm volatile("MOV " #Register ", %[PSP] "  : :[PSP] "r" (*(PSP_Pointer)))
#define OS_Enter_Critical_Section		__asm volatile ("cpsid i" : : : "memory")//Disable Interrupt
#define OS_Exit_Critical_Section		__asm volatile ("cpsie i" : : : "memory")//Enable Interrupt


void HW_init();
void Trigger_OS_PendSV();
void StartTicker();

#endif /* INC_CORTEXM3_4_OS_PORTING_H_ */
