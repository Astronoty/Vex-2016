int verticalInput = vexRT[Ch3];
int horizontalInput = vexRT[Ch1];
int slowTurn = vexRT[Btn8L]



void drivesys()
{
	//	int verticalInput, horizontalInput;
		int JOYSTICK_DEAD_ZONE = 10;

		if(abs(horizontalInput) > JOYSTICK_DEAD_ZONE) || (abs(verticalInput) > JOYSTICK_DEAD_ZONE)
		{
			if(slowTurn == 0)
			{
				int y = verticalInput;
				int x = horizontalInput;
			}
			
			else if(slowTurn == 1)
			{
				int y = verticalInput /2;
				int x = horizontalInput /2;
			}
			
			motor[port1] = y; 
			motor[port2] = y;			
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
