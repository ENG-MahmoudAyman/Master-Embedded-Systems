/*
 * US.h
 *
 *  Created on: Dec 19, 2023
 *      Author: engma
 */


#ifndef US_H_
#define US_H_

#include "State.h"
//define states
enum{
	US_busy,
};
extern int US_state_id;
//declare state function of CV
STATE_define(US_busy);
void init_US();
extern void (*US_state) ();


#endif /* US_H_ */
