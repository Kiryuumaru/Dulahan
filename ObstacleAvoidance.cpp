/*
 * ObstacleAvoidance.cpp
 *
 *  Created on: 25 Feb 2017
 *      Author: Beboy
 */

#include "DulahanAI.h"

static double SB = 0.5;
static long inch;
long criticalRange = 7;

void ObstacleAvoidanceLoop(){
	MR(240, 255, SB);
	inch = ReadDistance();
	Serial.println(inch);
	ObstacleAvoidanceRun();
	delay(50);
}

void ObstacleAvoidanceRun(){
	if(inch<criticalRange){
		Stop();delay(50);
		MR(-255, -255, SB);delay(300);
		Stop();delay(50);
		Face_Right();delay(300);
		inch = ReadDistance();
		Serial.print(inch);
		Serial.println("crit range");
		if(inch<criticalRange){
			Face_Back('L');
			delay(300);
			inch = ReadDistance();
			Serial.println("crit range");
			Serial.print(inch);
			if(inch<criticalRange){
				Face_Left();
			}
		}
	}
}
