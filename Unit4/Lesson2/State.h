/*
 * State.h
 *
 *  Created on: Dec 19, 2023
 *      Author: engma
 */

#ifndef STATE_H_
#define STATE_H_
//Automatic state function generated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

STATE_define(CA_waiting);
STATE_define(CA_driving);

void US_Get_Distance(int distance);
void DC_Motor_Set_Speed(int speed);

#endif /* STATE_H_ */
