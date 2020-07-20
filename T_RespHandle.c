/*
 * T_RespHandle.c
 *
 * Created: 7/20/2020 11:42:44 AM
 *  Author: BODY
 */ 
#include "T_RespHandle.h"

static INT8U RecPacket[30];

void T_RespHandle(void* pvData)
{	INT8U  U8_Byte         =0;
	RecevingState  Recevieng_State =0;
	INT8U Receive_Index =0 ;
	INT8U Remainig_Length =0;
	while(1)
	{
		if (UART_ReceiveByte_Unblock( UART_0 , &U8_Byte) )
		{
			switch (Recevieng_State)
			 {
					case RS_None: //RS ----> Receving State None ??!
					if (U8_Byte==0X20||   /*Connect Ack             */
						U8_Byte==0X30||   /* Packet type   -> QoS-0 */
						U8_Byte==0X32||   /* Packet type   -> QoS-1 */
						U8_Byte==0X40||  /* Publish Ack             */
						U8_Byte==0X90   /* Subscribe Ack            */
						)
					{
					RecPacket[0]=U8_Byte; /*Receiving and put it on the 1st index */
					Recevieng_State =RS_PacketType;
					}
					break;
					case RS_PacketType:
					RecPacket[1]=U8_Byte;
					Remainig_Length = U8_Byte;
					Receive_Index =0;
					Recevieng_State=RS_Remain;
					break;
					case RS_Remain:
					RecPacket[Receive_Index +2]=U8_Byte;
					Receive_Index++;
					if (Receive_Index == Remainig_Length)
					{ 
						Recevieng_State = RS_None;
						switch(RecPacket[0])
						{
							case 0x30:
							xQueueSend(mqControl,RecPacket,0);
							break;
							case 0x32:
							/*publish ack should be transmitted */
							break;
							case 0x20:
							xEventGroupSetBits(egMQTT,E_MQTT_CONNACK);
							break;
							case 0x40:
							xEventGroupSetBits(egMQTT,E_MQTT_PUBACK);
							break;
							case 0x90:
							xEventGroupSetBits(egMQTT,E_MQTT_SUBACK);
							break;	
						}
						
					}
					
					break;
			}
			
		}
		else vTaskDelay(1);
	}
}