#include "App.h"
/*OS Services */
/*Semaphore to communicate with MQTT Broker */
xSemaphoreHandle  bsConnect;
xQueueHandle      mqControl;
EventGroupHandle_t   egMQTT;
EventBits_t         ebValMQTT;
int main(void) 
{ 	System_Init();
	/*Create OS*/
	vSemaphoreCreateBinary(bsConnect,1);
	mqControl=xQueueCreate(2,30);
	egMQTT=xEventGroupCreate();
	/*create tasks*/
	xTaskCreate(T_Monitor,"T_Monitor",100,NULL,1,NULL);
	xTaskCreate(T_Control,"T_Control",100,NULL,2,NULL);
	xTaskCreate(T_Connect,"T_Connect",100,NULL,3,NULL);
	xTaskCreate(T_RespHandle,"T_RespHandle",100,NULL,4,NULL);
	/*Start OS*/
	vTaskStartScheduler();
	while (1)
		{}}
void System_Init(void)
{	Led_Init();
	MQTT_Init();
	ADC_INIT();
	Leds_Init(0X03);}
