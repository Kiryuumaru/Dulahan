/*
 * Sensor_IR.cpp
 *
 *  Created on: 4 Mar 2017
 *      Author: Beboy
 */

#include "DulahanAI.h"

String IRState;
static int i;
String ReadIRState()
{
	IRState = "";
	for(i = 0; i < IRSensorCount; i++)
	{
		int j = digitalRead(IRSensors[i]);
		if(j==LOW)
		{
			IRState += '0';
		}
		else
		{
			IRState += '1';
		}
	}
	return IRState;
}

bool lastLine_L = false;
bool lastLine_R = false;
String ReadIRStateExtension()
{
	IRState = ReadIRState();
	if(IRState=="1000")
	{
		lastLine_L = true;
		lastLine_R = false;
		return "01000000000";
	}
	else if(IRState=="1100")
	{
		lastLine_L = true;
		lastLine_R = false;
		return "00100000000";
	}
	else if(IRState=="0100")
	{
		lastLine_L = true;
		lastLine_R = false;
		return "00010000000";
	}
	else if(IRState=="1110")
	{
		delay(300);
		lastLine_L = true;
		lastLine_R = false;
		return "00001000000";
	}
	else if(IRState=="1111")
	{
		lastLine_L = false;
		lastLine_R = false;
		return "00000100000";
	}
	else if(IRState=="0110")
	{
		lastLine_L = false;
		lastLine_R = false;
		return "00000100000";
	}
	else if(IRState=="0111")
	{
		delay(300);
		lastLine_L = false;
		lastLine_R = true;
		return "00000010000";
	}
	else if(IRState=="0010")
	{
		lastLine_L = false;
		lastLine_R = true;
		return "00000001000";
	}
	else if(IRState=="0011")
	{
		lastLine_L = false;
		lastLine_R = true;
		return "00000000100";
	}
	else if(IRState=="0001")
	{
		lastLine_L = false;
		lastLine_R = true;
		return "00000000010";
	}
	else if(IRState=="0000")
	{
		if(lastLine_L)
		{
			return "10000000000";
		}
		else if(lastLine_R)
		{
			return "00000000001";
		}
	}
	return "00000000000";
}
