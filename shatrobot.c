
task main()
{
	for(int i = 0; i <= 3; i++)
	{
		motor[port2] = 50;
		wait1Msec(3000);
		motor[port2] = 0;
		wait1Msec(2000);
	}

}
