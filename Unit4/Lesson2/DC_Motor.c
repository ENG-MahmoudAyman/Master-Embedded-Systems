/*
 * CA.c
 *
 *  Created on: Dec 19, 2023
 *      Author: engma
 */

#include <stdio.h>
#include <stdlib.h>
#include "DC_Motor.h"
//variables
int DC_Motor_state_id;
static int DC_speed = 0;
void (*DC_Motor_state)();
void init_DC_Motor(){
	printf("init_DC_Motor\n");
}
void DC_Motor_Set_Speed(int speed){
	DC_speed = speed;
	DC_Motor_state = STATE(DC_Motor_busy);
	printf("CA ----> DC_Motor ____ speed = %d\n",DC_speed);
}
STATE_define(DC_Motor_idle){
	//state name
	DC_Motor_state_id = DC_Motor_idle;
	//action
	DC_Motor_state = STATE(DC_Motor_idle);
	printf("DC Idle state --- speed = %d\n",DC_speed);
}
STATE_define(DC_Motor_busy){
	//state name
	DC_Motor_state_id = DC_Motor_busy;
	//action
	DC_Motor_state = STATE(DC_Motor_idle);
	printf("DC Busy state --- speed = %d\n",DC_speed);
}

