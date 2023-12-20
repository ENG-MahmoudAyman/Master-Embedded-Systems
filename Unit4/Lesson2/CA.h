/*
 * CA.h
 *
 *  Created on: Dec 19, 2023
 *      Author: engma
 */
#include "State.h"

#ifndef CA_H_
#define CA_H_

//define states
enum{
	CA_waiting,
	CA_driving
};
extern int CA_state_id;
//declare state function of CV
STATE_define(CA_waiting);
STATE_define(CA_driving);

extern void (*CA_state) ();


#endif /* CA_H_ */
