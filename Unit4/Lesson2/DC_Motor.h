/*
 * DC_Motor.h
 *
 *  Created on: Dec 19, 2023
 *      Author: engma
 */
#include "State.h"

#ifndef DC_Motor_H_
#define DC_Motor_H_

//define states
enum{
	DC_Motor_idle,
	DC_Motor_busy
};
extern int DC_Motor_state_id;
//declare state function of CV
STATE_define(DC_Motor_idle);
STATE_define(DC_Motor_busy);
void init_DC_Motor();
extern void (*DC_Motor_state) ();


#endif /* DC_Motor_H_ */
