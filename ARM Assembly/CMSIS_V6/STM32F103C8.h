/**************************************************************************//**
 * @file     <Device>.h
 * @brief    CMSIS-Core(M) Device Header File for Device <Device>
 *
 * @version  V1.0.0
 * @date     18. July 2023
 ******************************************************************************/
/*
 * Copyright (c) 2009-2023 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* ToDo: rename this file from Device.h to '<Device>.h according to your device name */

#ifndef STMF103C8_H      /* ToDo: replace '<Device>' with your device name */
#define STMF103C8_H

#ifdef __cplusplus
extern "C" {
#endif


/* ========================================================================= */
/* ============           Interrupt Number Definition           ============ */
/* ========================================================================= */

typedef enum IRQn
{
	/* ================     Cortex-M Core Exception Numbers     ================ */

	/* ToDo: add Cortex exception numbers according the used Cortex-Core */
	Reset_IRQn = -15, /*  1 Reset Vector
	 invoked on Power up and warm reset */
	NonMaskableInt_IRQn = -14, /*  2 Non maskable Interrupt
	 cannot be stopped or preempted */
	HardFault_IRQn = -13, /*  3 Hard Fault
	 all classes of Fault */
	MemoryManagement_IRQn = -12, /*  4 Memory Management
	 MPU mismatch, including Access Violation and No Match */
	BusFault_IRQn = -11, /*  5 Bus Fault
	 Pre-Fetch-, Memory Access, other address/memory Fault */
	UsageFault_IRQn = -10, /*  6 Usage Fault
	 i.e. Undef Instruction, Illegal State Transition */
	SecureFault_IRQn = -9, /*  7 Secure Fault Interrupt */
	SVCall_IRQn = -5, /* 11 System Service Call via SVC instruction */
	DebugMonitor_IRQn = -4, /* 12 Debug Monitor */
	PendSV_IRQn = -2, /* 14 Pendable request for system service */
	SysTick_IRQn = -1, /* 15 System Tick Timer */

	/* ================        <Device> Interrupt Numbers       ================ */
	/* ToDo: Add here your device specific interrupt numbers
	 according the interrupt handlers defined in startup_Device.s
	 eg.: Interrupt for Timer#1       TIM1_IRQHandler   ->   TIM1_IRQn */
	WWDG_IRQn = 0,           // Window Watchdog Interrupt
	PVD_IRQn = 1,            // Power Voltage Detector Interrupt
	TAMPER_IRQn = 2,         // Tamper detection Interrupt
	RTC_IRQn = 3,            // Real-time clock Interrupt
	FLASH_IRQn = 4,           // Flash memory related Interrupt
	RCC_IRQn = 5,            // Clock control unit Interrupt


	// DMA Interrupts
	DMA1_Channel1_IRQn = 14,  // DMA1 Channel 1 transfer complete or error
	DMA1_Channel2_IRQn = 15,  // DMA1 Channel 2 transfer complete or error
	DMA1_Channel3_IRQn = 16,  // DMA1 Channel 3 transfer complete or error
	DMA1_Channel4_IRQn = 14,  // DMA1 Channel 4 transfer complete or error
	DMA1_Channel5_IRQn = 15,  // DMA1 Channel 5 transfer complete or error
	DMA1_Channel6_IRQn = 16,  // DMA1 Channel 6 transfer complete or error
	DMA1_Channel7_IRQn = 17,  // DMA1 Channel 7 transfer complete or error
	ADC1_2_IRQn = 18,          // ADC1 conversions (in some cases)

	// USB Interrupts
	USB_HP_CAN_TX_IRQn = 19,    // USB High-Priority CAN TX events
	USB_LP_CAN_RX0_IRQn = 20,   // USB Low-Priority CAN RX0 events

	// CAN Interrupts
	CAN_RX1_IRQn = 21,          // CAN module Receive 1
	CAN_SCE_IRQn = 22,          // CAN module Sleep Clock Exit

	// External Line Interrupts
	EXTI0_IRQn = 6,           // External Line 0 Interrupt
	EXTI1_IRQn = 7,           // External Line 1 Interrupt
	EXTI2_IRQn = 8,           // External Line 2 Interrupt
	EXTI3_IRQn = 9,           // External Line 3 Interrupt
	EXTI4_IRQn = 10,          // External Line 4 Interrupt
	EXTI9_5_IRQn = 23,          // External lines EXTI9 to EXTI5
	EXTI15_10_IRQn = 40,       // External lines EXTI15 to EXTI10

	// Timer Interrupts
	TIM1_BRK_TIM9_IRQn = 24,    // TIM1 Break event and/or TIM9 events
	TIM1_UP_TIM10_IRQn = 25,    // TIM1 Update event and/or TIM10 events
	TIM1_TRG_COM_TIM11_IRQn = 26,  // TIM1 Trigger/COM event and/or TIM11 events
	TIM1_CC_IRQn = 27,          // TIM1 Capture/Compare events
	TIM2_IRQn = 28,            // Timer 2 events
	TIM3_IRQn = 29,            // Timer 3 events
	TIM4_IRQn = 30,            // Timer 4 events

	// I2C Interrupts
	I2C1_EV_IRQn = 31,          // I2C1 Event
	I2C1_ER_IRQn = 32,          // I2C1 Error
	I2C2_EV_IRQn = 33,          // I2C2 Event
	I2C2_ER_IRQn = 34,          // I2C2 Error

	// USART Interrupts
	USART1_IRQn = 37, // USART1 events (e.g., Receive, Transmit Complete, Error)
	USART2_IRQn = 38,          // USART2 events
	USART3_IRQn = 39,          // USART3 events
	RTCAlarm_IRQn = 41

} IRQn_Type;


/* ========================================================================= */
/* ============      Processor and Core Peripheral Section      ============ */
/* ========================================================================= */

/* ================ Start of section using anonymous unions ================ */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* --------  Configuration of Core Peripherals  ----------------------------------- */
/* ToDo: set the defines according your Device */
/* ToDo: define the correct core revision
         valid CMSIS core revision macro names are:
           __CM0_REV, __CM0PLUS_REV, __CM1_REV, __CM3_REV, __CM4_REV, __CM7_REV
           __CM23_REV, __CM33_REV, __CM35P_REV, __CM55_REV
           __SC000_REV, __SC300_REV */
#define __CM3_REV               0x0201U  /* Core Revision r2p1 */
/* ToDo: define the correct core features for the <Device> */
#define __Vendor_SysTickConfig  0U       /* Set to 1 if different SysTick Config is used */
#define __NVIC_PRIO_BITS        3U       /* Number of Bits used for Priority Levels */
#define __VTOR_PRESENT          1U       /* Set to 1 if VTOR is present */
#define __MPU_PRESENT           1U       /* Set to 1 if MPU is present */
#define __FPU_PRESENT           0U       /* Set to 1 if FPU is present */
#define __FPU_DP                0U       /* Set to 1 if FPU is double precision FPU (default is single precision FPU) */
#define __DSP_PRESENT           1U       /* Set to 1 if DSP extension are present */
#define __SAUREGION_PRESENT     1U       /* Set to 1 if SAU regions are present */
#define __PMU_PRESENT           1U       /* Set to 1 if PMU is present */
#define __PMU_NUM_EVENTCNT      8U       /* Set number of PMU Event Counters */
#define __ICACHE_PRESENT        0U       /* Set to 1 if I-Cache is present */
#define __DCACHE_PRESENT        0U       /* Set to 1 if D-Cache is present */
#define __DTCM_PRESENT          0U       /* Set to 1 if DTCM is present */


/* ToDo: include the CMSIS core header file according your device.
         valid CMSIS core header files are:
           core_cm0.h, core_cm0plus.h, core_cm1.h, core_cm3.h, core_cm4.h, core_cm7.h
           core_cm23.h, core_cm33.h, core_cm35p.h, core_cm55.h
           core_sc000.h, core_sc300.h */
#include <core_cm3.h>                          /* Processor and core peripherals */
/* ToDo: include your system_<Device>.h file
         replace '<Device>' with your device name */
#include <system_STM32F103C8.h>                    /* System Header */



/* ========================================================================= */
/* ============       Device Specific Peripheral Section        ============ */
/* ========================================================================= */


/* ToDo: add here your device specific peripheral access structure typedefs
         including bit definitions for Pos/Msk macros
         following is an example for a timer */

/* ========================================================================= */
/* ============                       TMR                       ============ */
/* ========================================================================= */

typedef struct
{
  __IOM uint32_t  LOAD;                 /* Offset: 0x000 (R/W) Load Register */
  __IM  uint32_t  VALUE;                /* Offset: 0x004 (R/ ) Value Register */
  __IOM uint32_t  CONTROL;              /* Offset: 0x008 (R/W) Control Register */
  __OM  uint32_t  INTCLR;               /* Offset: 0x00C ( /W) Clear Interrupt Register */
  __IM  uint32_t  RIS;                  /* Offset: 0x010 (R/ ) Raw Interrupt Status Register */
  __IM  uint32_t  MIS;                  /* Offset: 0x014 (R/ ) Interrupt Status Register */
  __IOM uint32_t  BGLOAD;               /* Offset: 0x018 (R/W) Background Load Register */
} STM32F103C8_TMR_TypeDef;

/* STM32F103C8_TMR LOAD Register Definitions */
#define STM32F103C8_TMR_LOAD_Pos              0
#define STM32F103C8_TMR_LOAD_Msk             (0xFFFFFFFFUL /*<< STM32F103C8_TMR_LOAD_Pos*/)

/* STM32F103C8_TMR VALUE Register Definitions */
#define STM32F103C8_TMR_VALUE_Pos             0
#define STM32F103C8_TMR_VALUE_Msk            (0xFFFFFFFFUL /*<< STM32F103C8_TMR_VALUE_Pos*/)

/* STM32F103C8_TMR CONTROL Register Definitions */
#define STM32F103C8_TMR_CONTROL_SIZE_Pos      1
#define STM32F103C8_TMR_CONTROL_SIZE_Msk     (1UL << STM32F103C8_TMR_CONTROL_SIZE_Pos)

#define STM32F103C8_TMR_CONTROL_ONESHOT_Pos   0
#define STM32F103C8_TMR_CONTROL_ONESHOT_Msk  (1UL /*<< STM32F103C8_TMR_CONTROL_ONESHOT_Pos*/)



/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* ========================================================================= */
/* ============     Device Specific Peripheral Address Map      ============ */
/* ========================================================================= */


/* ToDo: add here your device peripherals base addresses
         following is an example for timer */

/* Peripheral and SRAM base address */
#define STM32F103C8_FLASH_BASE       (0x00000000UL)                              /* (FLASH     ) Base Address */
#define STM32F103C8_SRAM_BASE        (0x20000000UL)                              /* (SRAM      ) Base Address */
#define STM32F103C8_PERIPH_BASE      (0x40000000UL)                              /* (Peripheral) Base Address */

/* Peripheral memory map */
#define STM32F103C8TIM0_BASE         (STM32F103C8_PERIPH_BASE)          /* (Timer0    ) Base Address */
#define STM32F103C8TIM1_BASE         (STM32F103C8_PERIPH_BASE + 0x0800) /* (Timer1    ) Base Address */
#define STM32F103C8TIM2_BASE         (STM32F103C8_PERIPH_BASE + 0x1000) /* (Timer2    ) Base Address */


/* ========================================================================= */
/* ============             Peripheral declaration              ============ */
/* ========================================================================= */


/* ToDo: Add here your device peripherals pointer definitions
         following is an example for timer */

#define STM32F103C8_TIM0        ((STM32F103C8_TMR_TypeDef *) STM32F103C8TIM0_BASE)
#define STM32F103C8_TIM1        ((STM32F103C8_TMR_TypeDef *) STM32F103C8TIM0_BASE)
#define STM32F103C8_TIM2        ((STM32F103C8_TMR_TypeDef *) STM32F103C8TIM0_BASE)

#ifdef __cplusplus
}
#endif

#endif  /* <Device>_H */
