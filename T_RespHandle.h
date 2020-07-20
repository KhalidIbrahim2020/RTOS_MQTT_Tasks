/*
 * T_RespHandle.h
 *
 * Created: 7/20/2020 11:39:58 AM
 *  Author: BODY
 */ 


#ifndef T_RESPHANDLE_H_
#define T_RESPHANDLE_H_

#include "App.h"
extern  xSemaphoreHandle    bsConnect;
extern xQueueHandle         mqControl;
extern EventGroupHandle_t   egMQTT;
extern EventBits_t          ebValMQTT;

typedef enum
	{
		RS_None , RS_PacketType ,RS_Remain 
		
	}RecevingState;












#endif /* T_RESPHANDLE_H_ */