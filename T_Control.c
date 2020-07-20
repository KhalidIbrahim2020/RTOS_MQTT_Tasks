

#include "T_Control.h"

static INT8U CMDPacket[30];

/*L1 -> Led on , L0 -> Led off*/

void T_Control(void* pvData)
{
	INT8U ind =0;
	while(1)
	{
		if(xQueueReceive(mqControl/*Msg Queue Control*/,CMDPacket/*Packet from Broker*/,portMAX_DELAY/*Wait Till get it from Queue*/))
		{
			for(ind=0; ind<CMDPacket[1];ind++)
			{
				if(CMDPacket[ind+2]=='$')
				{
					
					if (CMDPacket[ind+2+1]=='A')
					{
						if (CMDPacket[ind+2+1+1]=='C')
						{
							if     (CMDPacket[ind+2+1+1+1]=='0')
							{
								Led_On();
							}
							else if(CMDPacket[ind+2+1+1+1]=='1')
							{
								Led_Off();
							}
						}

					}
				if (CMDPacket[ind+2+1]=='T')
				{
					if (CMDPacket[ind+2+1+1]=='V')
					{
						if     (CMDPacket[ind+2+1+1+1]=='0')
						{
							Leds_On(0x02);
						}
						else if(CMDPacket[ind+2+1+1+1]=='1')
						{
							Leds_Off(0x02);
						}	
				}
			}
		}
	
	}
			}
		}
	}

					