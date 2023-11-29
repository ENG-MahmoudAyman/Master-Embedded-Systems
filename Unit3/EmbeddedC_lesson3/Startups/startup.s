/* Mahmoud Ayman
MCU Cortex M3 startup.s */
/* SRAM START at 0x20000000 */

.section .vectors

.word 0x20001000         /* Stack Top address */
.word _reset             /* 1 Reset */
.word Vector_handler     /* 2 NMI */
.word Vector_handler     /* 3 HardFault */
.word Vector_handler     /* 4 MemManage */
.word Vector_handler     /* 5 BusFault */
.word Vector_handler     /* 6 UsageFault */
.word Vector_handler     /* 7 Reserved */
.word Vector_handler     /* 8 Reserved */
.word Vector_handler     /* 9 Reserved */
.word Vector_handler     /* 10 Reserved */
.word Vector_handler     /* 11 SVCall */
.word Vector_handler     /* 12 Debug Monitor */
.word Vector_handler     /* 13 Reserved */
.word Vector_handler     /* 14 PendSV */
.word Vector_handler     /* 15 SysTick */
.word Vector_handler     /* 16 WWDG */
.word Vector_handler     /* 17 PVD */
.word Vector_handler     /* 18 TAMPER */
.word Vector_handler     /* 19 RTC */
       /* And so on */

.section .text

_reset:
	bl main
	b .
.thumb_func
Vector_handler:
	b _reset
