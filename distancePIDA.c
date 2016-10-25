#pragma config(Sensor, dgtl1,  rightEnc,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEnc,        sensorQuadEncoder)
#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftBottomLift, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           rightBottomLift, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftClaw,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightDrive,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftDrive,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rightClaw,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           rightTopLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           leftTopLift,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightH,        tmotorVex393_HBridge, openLoop)

#define PID_INTEGRAL_LIMIT  50
#define PID_DRIVE_MAX       127
#define PID_DRIVE_MIN     (-127)
#define PID_SENSOR_SCALE (-1)


static float pidRequestedValueLeft, pidRequestedValueRight;
static float  Kp = 0.5;
static float  Ki = 0.04;
static float  Kd = 0.0;
static bool pidActive = true;


task pidController()
{
	 //Initialize variables
	 float  pidSensorCurrentValueLeft, pidSensorCurrentValueRight;
   float  pidErrorLeft, pidErrorRight;
   float  pidLastErrorLeft, pidLastErrorRight;
   float  pidIntegralLeft, pidIntegralRight;
   float  pidDerivativeLeft, pidDerivativeRight;
   float  pidDriveLeft, pidDriveRight;

   //Clear sensor values
   SensorValue[rightEnc] = 0;
   SensorValue[leftEnc] = 0;

   pidLastErrorLeft = 0;
   pidLastErrorRight = 0;
   pidIntegralLeft = 0;
   pidIntegralRight = 0;

   while(true)
   {

   	 //If the pid is set to active
     if(pidActive)
     {
       //Calculate proportional portion
		       pidSensorCurrentValueLeft = SensorValue[leftEnc]* PID_SENSOR_SCALE;
		       pidSensorCurrentValueRight = SensorValue[rightEnc] * PID_SENSOR_SCALE;

		       pidErrorLeft = pidSensorCurrentValueLeft - pidRequestedValueLeft;
		       pidErrorRight = pidSensorCurrentValueRight -pidRequestedValueRight;
			 // Calculate integral portion
		 			 // Add the error to the integral if it is outside the controllable range of values
		       if(abs(pidErrorLeft) < PID_INTEGRAL_LIMIT)
		            pidIntegralLeft = pidIntegralLeft + pidErrorLeft;
		       else
		            pidIntegralLeft = 0;

		       if(abs(pidErrorRight) < PID_INTEGRAL_LIMIT)
		            pidIntegralRight = pidIntegralRight + pidErrorRight;
		       else
		            pidIntegralRight = 0;

	      // Calculate derivitave portion
		  			pidDerivativeLeft = pidErrorLeft - pidLastErrorLeft;
		  			pidDerivativeRight = pidErrorRight - pidLastErrorRight;

		        pidLastErrorLeft  = pidErrorLeft;
		        pidLastErrorRight = pidErrorRight;

		     // calculate drive
            pidDriveLeft = (Kp * pidErrorLeft) + (Ki * pidIntegralLeft) + (Kd * pidDerivativeLeft);
            pidDriveRight = (Kp * pidErrorRight) + (Ki * pidIntegralRight) + (Kd * pidDerivativeRight);

         // limit drive
            if( pidDriveLeft > PID_DRIVE_MAX )
                pidDriveLeft = PID_DRIVE_MAX;
            if( pidDriveLeft < PID_DRIVE_MIN )
                pidDriveLeft = PID_DRIVE_MIN;

            if( pidDriveRight > PID_DRIVE_MAX )
                pidDriveRight = PID_DRIVE_MAX;
            if( pidDriveRight < PID_DRIVE_MIN )
                pidDriveRight = PID_DRIVE_MIN;

         // DRIVE BOI DRIVE
            motor[leftDrive] = pidDriveLeft;
            motor[rightDrive] = pidDriveRight;
     }
     else // delete the emails, i mean variables
     {
       pidSensorCurrentValueLeft = 0;
       pidSensorCurrentValueRight = 0;
       pidErrorLeft = 0;
       pidErrorRight = 0;
       pidLastErrorLeft = 0;
       pidLastErrorRight = 0;
       pidIntegralLeft = 0;
       pidIntegralRight = 0;
       pidDerivativeLeft = 0;
       pidIntegralRight = 0;
       pidDriveLeft= 0;
       pidDriveRight = 0;
     }
   }
}



task main()
{
 // send the motor off somewhere
    pidRequestedValueLeft = 1000;
    pidRequestedValueRight = 1000;

    // start the PID task
    startTask(pidController);


}
