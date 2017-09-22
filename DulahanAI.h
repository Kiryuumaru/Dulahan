#ifndef _DulahanAI_H_
#define _DulahanAI_H_
#include "Arduino.h"

//
//AI Config
//
const double motorSpeedMultiplier_L = 1;
const double motorSpeedMultiplier_R = 1;
const double facingSpeedMultiplier = 1;
const int facingDelay = 500;
//
//Pin config
//
const int motorL_N = 3;
const int motorL_P = 5;
const int motorR_N = 6;
const int motorR_P = 9;
const int IRSensors[] = {2, 4, 7, 8};
const int IRSensorCount = 4;
const int ultrasonicTrig = 8;
const int ultrasonicEcho = 10;
//
//Sensor_IR
//
String ReadIRState();
String ReadIRStateExtension();
//
//Sensor_Ulatrasonic
//
int ReadDistance();
//
//Motor
//
void MR(int mL, int mR, double speedMultiplier);
void RMR(int mL, int mR, double speedMultiplier);
void Face_Left();
void Face_Right();
void Face_Back(char turn);
void Rotate(char turn, double speedMultiplier);
void Stop();
void ConfigMotor_L(int mL, double speedMultiplier);
void ConfigMotor_R(int mR, double speedMultiplier);
//
//LineFollower
//
void LineFollowerLoop();
void LineFollowerRun(String state);
//
//Obstacle Avoidance
//
void ObstacleAvoidanceLoop();
void ObstacleAvoidanceRun();


#endif
