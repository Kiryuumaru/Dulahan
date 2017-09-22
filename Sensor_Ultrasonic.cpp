/*
 * Sensor_Ultrasonic.cpp
 *
 *  Created on: 4 Mar 2017
 *      Author: Beboy
 */

#include "DulahanAI.h"

int duration;
int ReadDistance()
{
	digitalWrite(ultrasonicTrig, LOW);
	delayMicroseconds(2);
	digitalWrite(ultrasonicTrig, HIGH);
	delayMicroseconds(2);
	digitalWrite(ultrasonicTrig, LOW);
	duration = pulseIn(ultrasonicEcho, HIGH);
	return duration/74/2;
}
