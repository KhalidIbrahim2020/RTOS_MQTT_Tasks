/*
 * T_Control.h
 *
 * Created: 7/20/2020 11:39:15 AM
 *  Author: BODY
 */ 


#ifndef T_CONTROL_H_
#define T_CONTROL_H_

#include "App.h"
extern  xSemaphoreHandle    bsConnect;
extern xQueueHandle         mqControl;
extern EventGroupHandle_t   egMQTT;
extern EventBits_t           ebValMQTT;
extern    INT8U System_Up;


#endif /* T_CONTROL_H_ */