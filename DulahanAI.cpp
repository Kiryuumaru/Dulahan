#include "DulahanAI.h"

static int i;
void setup()
{
	Serial.begin(9600);
	pinMode(motorL_N, OUTPUT);
	pinMode(motorL_P, OUTPUT);
	pinMode(motorR_N, OUTPUT);
	pinMode(motorR_P, OUTPUT);
	for(i = 0; i < IRSensorCount; i++)
	{
		pinMode(IRSensors[i], INPUT);
	}
}

void loop()
{
	LineFollowerLoop();
}
