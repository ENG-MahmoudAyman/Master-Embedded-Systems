/*
 * CA.c
 *
 *  Created on: Dec 19, 2023
 *      Author: engma
 */

#include <stdio.h>
#include <stdlib.h>
#include "CA.h"
//variables
int CA_state_id;
static int CA_distance = 0;
static int CA_speed = 0;
static int CA_threshold = 50;

void (*CA_state)();
void US_Get_Distance(int distance){
	CA_distance = distance;
	CA_state = (CA_distance <= CA_threshold)? STATE(CA_waiting):STATE(CA_driving);
	printf("US -----> CA ____ Distance = %d\n",CA_distance);
}

STATE_define(CA_waiting){
	//state name
	CA_state_id = CA_waiting;
	printf("CA Waiting State: distance = %d speed = %d \n",CA_distance, CA_speed);
	//action
	CA_speed = 0;
	DC_Motor_Set_Speed(CA_speed);
}

STATE_define(CA_driving){
	//state name
	CA_state_id = CA_driving;
	printf("CA Driving State: distance = %d speed = %d \n",CA_distance, CA_speed);
	//action
	CA_speed = 30;
	DC_Motor_Set_Speed(CA_speed);
}

