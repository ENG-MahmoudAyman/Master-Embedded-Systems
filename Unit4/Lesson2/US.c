/*
 * CA.c
 *
 *  Created on: Dec 19, 2023
 *      Author: engma
 */

#include <stdio.h>
#include <stdlib.h>
#include "US.h"
//variables
int US_state_id;
static int US_distance = 0;
int US_Get_distance_random(int,int);
void (*US_state)();
void init_US(){
	printf("init_US\n");
}
STATE_define(US_busy){
	//state name
	US_state_id = US_busy;
	//US get distance
	US_distance = US_Get_distance_random(45,55);
	//event check
	printf("US busy state: distance = %d\n",US_distance);
	US_Get_Distance(US_distance);
	US_state = STATE(US_busy);
}

int US_Get_distance_random(int L,int R){
	return ((rand()%(R-L+1))+L);
}
