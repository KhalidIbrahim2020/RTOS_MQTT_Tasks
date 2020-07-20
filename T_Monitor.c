/*
 * T_Monitor.c
 *
 * Created: 7/20/2020 11:42:26 AM
 *  Author: BODY
 */ 
#include "T_Monitor.h"

void T_Monitor(void* pvData)
{
	INT8U  Temperature =0;
	INT16U AdcValue   =0;
	EventBits_t ebvalues =0;
	while(1)
	{
		/* System_Up (Created at T_Connect ) :is set after connect */
		
	if ( System_Up ==1)
	 {
	 	
		/* Read Temp From Sensor */
		AdcValue = ADC_Read(0);
		Temperature = ((AdcValue/1023.0)*150);
		
		/*Publish Temperature */
		MQTT_Publish("monitor",&Temperature ,1,1);
		/*  Wait For Publish Ack   */
		
		ebvalues = xEventGroupWaitBits(egMQTT,E_MQTT_CONNACK,1,0,5000);
		if (ebvalues & E_MQTT_PUBACK)
		{
			/*Publish Done*/
		}
		else
		{
			System_Up =0;
			xSemaphoreGive(bsConnect);
			
		}
	}
		vTaskDelay(10000);
	}
}