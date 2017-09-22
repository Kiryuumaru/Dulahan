/*
 * *****************************
 * Project Celty
 * Clynt Neiko J. Rupinta
 * BSCPE3A_C1
 * University of Science and Technology of Southern Philippines
 * *****************************
 */

#include "DulahanAI.h"

void MR (int mL, int mR, double speedMultiplier)
{
	ConfigMotor_L(mL, speedMultiplier * motorSpeedMultiplier_L);
	ConfigMotor_R(mR, speedMultiplier * motorSpeedMultiplier_R);
}

void RMR(int mL, int mR, double speedMultiplier)
{
	ConfigMotor_R(-mL, speedMultiplier * motorSpeedMultiplier_R);
	ConfigMotor_L(-mR, speedMultiplier * motorSpeedMultiplier_L);
}

void Face_Left()
{
	Stop();
	MR(-255, 255, facingSpeedMultiplier);
	delay(facingDelay);
	Stop();
}

void Face_Right()
{
	Stop();
	MR(255, -255, facingSpeedMultiplier);
	delay(facingDelay);
	Stop();
}

void Face_Back(char turn)
{
	switch(turn){
	case 'L':
		Stop();
		MR(-255, 255, facingSpeedMultiplier);
		delay(facingDelay*2);
		Stop();
		break;
	case 'R':
		Stop();
		MR(255, -255, facingSpeedMultiplier);
		delay(facingDelay*2);
		Stop();
		break;
	}
}

void Rotate(char turn, double speedMultiplier)
{
	switch(turn)
	{
		case 'L':
			MR(-255, 255, speedMultiplier);
			break;
		case 'R':
			MR(255, -255, speedMultiplier);
			break;
	}
}

void Stop()
{
	MR(0, 0, 1);
}

void ConfigMotor_L(int mL, double speedMultiplier)
{
	if(mL >= 0)
	{
		analogWrite(motorL_P, mL*speedMultiplier);
		analogWrite(motorL_N, 0);
	}
	else
	{
		analogWrite(motorL_N, -mL*speedMultiplier);
		analogWrite(motorL_P, 0);
	}
}

void ConfigMotor_R(int mR, double speedMultiplier)
{
	if(mR >= 0)
	{
		analogWrite(motorR_P, mR*speedMultiplier);
		analogWrite(motorR_N, 0);
	}
	else
	{
		analogWrite(motorR_N, -mR*speedMultiplier);
		analogWrite(motorR_P, 0);
	}
}
