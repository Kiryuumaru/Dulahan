/*
 * LineFollower.cpp
 *
 *  Created on: 25 Feb 2017
 *      Author: Beboy
 */

#include "DulahanAI.h"

double speedMultiplier = 1;
double updateDelay = 10;

void LineFollowerLoop()
{
	String state = ReadIRStateExtension();
	LineFollowerRun(ReadIRStateExtension());
	delay(updateDelay);
}

void LineFollowerRun(String state)
{
	Serial.println(state);
	if(state=="00000000000")
	{
		Rotate('L', speedMultiplier);
	}
	else if(state=="10000000000")
	{
		Rotate('L', speedMultiplier);
	}
	else if(state=="01000000000")
	{
		MR(0, 255, speedMultiplier);
	}
	else if(state=="00100000000")
	{
		MR(75, 255, speedMultiplier);
	}
	else if(state=="00010000000")
	{
		MR(125, 255, speedMultiplier);
	}
	else if(state=="00001000000")
	{
		MR(175, 255, speedMultiplier);
	}
	else if(state=="00000100000")
	{
		MR(255, 255, speedMultiplier);
	}
	else if(state=="00000010000")
	{
		MR(255, 175, speedMultiplier);
	}
	else if(state=="00000001000")
	{
		MR(255, 125, speedMultiplier);
	}
	else if(state=="00000000100")
	{
		MR(255, 75, speedMultiplier);
	}
	else if(state=="00000000010")
	{
		MR(255, 0, speedMultiplier);
	}
	else if(state=="00000000001")
	{
		Rotate('R', speedMultiplier);
	}
}
