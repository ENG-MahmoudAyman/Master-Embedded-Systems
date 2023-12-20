/*
 * main.c
 *
 *  Created on: Dec 19, 2023
 *      Author: engma
 */
#include <stdio.h>
#include "CA.h"
#include "US.h"
#include "DC_Motor.h"

void setup(){
	init_US();
	init_DC_Motor();
	CA_state = STATE(CA_waiting);
	DC_Motor_state = STATE(DC_Motor_idle);
	US_state = STATE(US_busy);
}

int main(){
	volatile int d;
	setup();
	while(1){
		US_state();
		CA_state();
		DC_Motor_state();
		for(d=0;d<1000;d++);
	}
	return 0 ;
}
