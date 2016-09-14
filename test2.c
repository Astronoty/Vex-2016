



void drivesys()
{
	//	int verticalInput, horizontalInput;
		int JOYSTICK_DEAD_ZONE = 10;
		int verticalInput = vexRT[Ch3];
		int horizontalInput = vexRT[Ch1];

		if(abs(horizontalInput) > JOYSTICK_DEAD_ZONE) || (abs(verticalInput) > JOYSTICK_DEAD_ZONE)
		{
			int meme = 0;
			int y = verticalInput;
			int x = horizontalInput;
			
			motor[port1] = y; //placeholder motor; replace y with PID request
			motor[port2] = y;  //"
			
		}
}

void drivesysPID()
{
	int meme = 0;
}


task main()
{
	drivesys();


}
