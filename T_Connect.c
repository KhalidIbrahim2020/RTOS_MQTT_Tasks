/*
 * T_Connect.c
 *
 * Created: 7/20/2020 11:43:12 AM
 *  Author: BODY
 */ 
#include "T_Connect.h"

INT8U System_Up;

void T_Connect(void* pvData)
{
	EventBits_t ebvalues =0;
	while(1)
	{		/*wait for disconnection */
		if (xSemaphoreTake(bsConnect,portMAX_DELAY))
		{
			/*connect*/
			MQTT_Connect("Khg!96");
			/* CONNACK */
			ebvalues = xEventGroupWaitBits(egMQTT//Event Group
			,E_MQTT_CONNACK//Wait for conn ack
			,1//Clear
			,0,5000);
			if (ebvalues & E_MQTT_CONNACK)
			{
				/* Connect Done */
				/* Subscribe */
				vTaskDelay(1000);
				MQTT_Subscribe("control");
				
				/**********************************************/
				/* SUBSCRIBE ACK */
				ebvalues = xEventGroupWaitBits(egMQTT//eventGroup
				,E_MQTT_SUBACK//wait for
				,1//clear
				,0//independent waiting 
				,5000 //wait
				);
				
				if (ebvalues & E_MQTT_SUBACK)
				{
					/*Done*/
					System_Up=1;
				}
				else{xSemaphoreGive(bsConnect);}//make sure its connected
				/**********************************************/
			}
			else 
			{
				System_Up =0;
				xSemaphoreGive(bsConnect);
				
			}
		}
	}
}