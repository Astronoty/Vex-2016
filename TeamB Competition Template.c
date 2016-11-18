#pragma config(Sensor, dgtl1,  leftFrontEnc,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftBackEnc,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  rightFrontEnc,  sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  rightBackEnc,   sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  bumpSwitch,     sensorTouch)
#pragma config(Motor,  port1,           leftClaw,      tmotorNone, openLoop)
#pragma config(Motor,  port2,           leftFrontD,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftBackD,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftLift3,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           leftLift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           rightFrontD,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightBackD,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightLift3,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightClaw,     tmotorVex393_HBridge, openLoop, reversed)

#pragma platform(VEX2)
//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(145)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.`
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

int JOYSTICK_DEAD_ZONE = 10;


void xDrive()
{
	int x = vexRT[Ch4];
	int y = vexRT[Ch3];
	int r = vexRT[Ch1];
	if(abs(x) < JOYSTICK_DEAD_ZONE)
		x = 0;
	if(abs(y) < JOYSTICK_DEAD_ZONE)
		y = 0;



	if(vexRT[Btn8L] == 1)
	{
		int x = x / 2;
		int y = y / 2;
		int r = r / 2;
	}

	motor[leftFrontD] = x + y + r;
	motor[rightFrontD] = x - y + r;
	motor[leftBackD] = -x + y + r;
	motor[rightBackD] = -x - y + r;

}

void lift()
{
	if (SensorValue(bumpSwitch) == 1)
	{
		motor[leftLift] = 20;
		motor[rightLift] = 20;
		motor[rightLift3] = 20;
    motor[leftLift3] = 20;
	}
	else
 if (vexRT[Btn6U]==1)
 {
   motor[rightLift]=127;
   motor[leftLift]=127;
   motor[rightLift3] = 127;
   motor[leftLift3] = 127;
 }
 else
 if (vexRT[Btn6D]==1)
 {
   motor[rightLift]=-127;
   motor[leftLift]=-127;
   motor[rightLift3] = -127;
   motor[leftLift3] = -127;
 }
 else
 {
   motor[rightLift]=20;
   motor[leftLift]=20;
   motor[rightLift3] = 20;
   motor[leftLift3] = 20;
 }
}

void intake()
{
	if(vexRT[Btn5U] == 1)
	{
		motor[leftClaw] = 127;
		motor[rightClaw] = 127;
	}
	else
	if(vexRT[Btn5D] == 1)
	{
		motor[leftClaw] = -127;
		motor[rightClaw] = -127;
	}
	else
  {
		motor[leftClaw] = 0;
		motor[rightClaw] = 0;
	}
}

task usercontrol()
{
	while(true)
	{
		xDrive();
		lift();
		intake();
		wait1Msec(50);
	}
}
