/*
 * T_Connect.h
 *
 * Created: 7/20/2020 11:40:42 AM
 *  Author: BODY
 */ 


#ifndef T_CONNECT_H_
#define T_CONNECT_H_

#include "App.h"
extern  xSemaphoreHandle    bsConnect;
extern xQueueHandle         mqControl;
extern EventGroupHandle_t   egMQTT;
extern EventBits_t   ebValMQTT;



#endif /* T_CONNECT_H_ */