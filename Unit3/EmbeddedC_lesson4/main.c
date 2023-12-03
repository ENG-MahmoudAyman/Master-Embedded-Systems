/**
 ******************************************************************************
 * @file           : main.c 
 * @author         : Mahmoud Ayman
 * @brief          : Main program body Cortex M4 TIVA C
 ******************************************************************************
**/
#include "platform_Types.h"

#define SYSCTL_BASE         0x400FE000
#define GPIOF_BASE          0x40025000
#define SYSCTL_RCGC2_R      *(vuint32 *) (SYSCTL_BASE + 0x108)
#define GPIO_PORTF_DIR_R    *(vuint32 *) (GPIOF_BASE + 0x400)
#define GPIO_PORTF_DATA_R   *(vuint32 *) (GPIOF_BASE + 0x3FC)
#define GPIO_PORTF_DEN_R    *(vuint32 *) (GPIOF_BASE + 0x51C)

#define PF(x)                          (x)
#define SET_BIT(Regiter,bit)           (Regiter|= (1UL<<bit))
#define RESET_HBYTE(Regiter,S_bit)     (Regiter &= ~(0x0F<<S_bit))

typedef union{
	vuint32    PORT;
	struct{
		vuint32	  P_0:1;
		vuint32	  P_1:1;
		vuint32	  P_2:1;
		vuint32	  P_3:1;
		vuint32	  P_4:1;
		vuint32	  P_5:1;
		vuint32	  P_6:1;
		vuint32	  P_7:1;
	
	}PIN;

}P_R_t;

volatile P_R_t* PF_DATA = (volatile P_R_t*) (GPIOF_BASE + 0x3FC);
volatile P_R_t* PF_DIR = (volatile P_R_t*)  (GPIOF_BASE + 0x400);
volatile P_R_t* PF_DEN = (volatile P_R_t*)  (GPIOF_BASE + 0x51C);
uint8 g_variables[3] = {1,2,3};
uint8 const Const_variables[3] = {1,2,3};
uint8 bss_var[3];
int main(void)
{
	SYSCTL_RCGC2_R = 0x00000020;
	for(vuint8 i = 0;i<200;i++);
	SET_BIT(GPIO_PORTF_DIR_R,PF(3));
	//PF_DIR->PIN.P_3 = 1;
	SET_BIT(GPIO_PORTF_DEN_R,PF(3));
	//PF_DEN->PIN.P_3 = 1;

	while(1){
		PF_DATA->PIN.P_3 = 1;
		//GPIO_PORTF_DATA_R|=(1<<PF(3));
		for(vuint32 i = 0;i<500000;i++);
		PF_DATA->PIN.P_3 = 0;
		//GPIO_PORTF_DATA_R&=~(1<<PF(3));
		for(vuint32 i = 0;i<500000;i++);
	}

}
