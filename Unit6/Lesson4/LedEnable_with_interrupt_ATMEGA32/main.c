/*
 * main.c
 *
 *  Created on: Dec 29, 2023
 *      Author: engma
 */

#include"platform_Types.h"
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

//Macros
#define SET_BIT(Regiter,bit)     (Regiter|= (1UL<<bit))
#define RESET_BIT(Regiter,bit)     (Regiter&= ~(1UL<<bit))
#define SET_HBYTE(Regiter,S_bit)     (Regiter |= (0x0F<<S_bit))
#define RESET_HBYTE(Regiter,S_bit)     (Regiter &= ~(0x0F<<S_bit))
//default 1MHZ  CKSEL = “0001” and SUT = “10”
void init_GPIO(){
	//PD2 Input No pull up
	RESET_BIT(DDRD,2);
	RESET_BIT(PORTD,2);
	//PC0 Output
	SET_BIT(DDRC,0);
}
void init_EXTI(){
	SET_BIT(MCUCR,0);//change mode Int0
	SET_BIT(GICR,6);//Enable Int0
	SET_BIT(SREG,7);//global interrupt enable
}
int main(void){
	init_GPIO();
	init_EXTI();
	while(1);
	return 0;
}
ISR(INT0_vect)
{
	SET_BIT(PORTC,0);
	_delay_ms(1000);
	RESET_BIT(PORTC,0);
	//default
	SET_BIT(GIFR,6);
}
