
void playMusic()
{
	//cuttime
	playTone(698.46, 49); //F5 half
	wait10Msec(1);

	playTone(783.99, 24.5); //G5 quarter
	wait10Msec(.5);

	playTone(783.99, 24.5); //G5 quarter
	wait10Msec(.5);

	playTone(659.25, 12.25); //E5 eighth
	wait10Msec(.25);

	playTone(587.33, 12.25);//D5 eighth
	wait10Msec(.25);

	playTone(466.16, 12.25);//A4 eighth sharp
	wait10Msec(.25);

	playTone(493.88, 12.25);//B4 eighth
	wait10Msec(.25);

	playTone(587.33, 12.25);//D5 eighth
	wait10Msec(.25);

	playTone(493.88, 12.25);//B4 eighth
	wait10Msec(.25);

	playTone(659.25, 24.5); //E5 quarter
	wait10Msec(.5);

	playTone(587.33, 12.25);//D5 eighth
	wait10Msec(.25);

	playTone(493.88, 12.25);//B4 eighth
	wait10Msec(.25);

	playTone(440.00, 12.25);//A4 eighth
	wait10Msec(.25);

	playTone(392.00, 12.25);//G4 eighth
	wait10Msec(.25);

	playTone(392.00, 24.5);//G4 quarter
	wait10Msec(.5);

	playTone(392.00, 12.25);//G4 eighth
	wait10Msec(.25);

	playTone(493.88, 24.5);//B4 eighth tied eighth = quarter
	wait10Msec(.5);

	playTone(587.33, 12.25);//D5 eighth
	wait10Msec(.25);

	playTone(659.25, 12.25); //E5 eighth
	wait10Msec(.25);

	playTone(587.33, 12.25);//D5 eighth
	wait10Msec(.25);

	playTone(783.99, 24.5); //G5 quarter
	wait10Msec(.5);





	//old
	//B4 eighth

	//A4 quarter

	//G4 quarter

	//A4 eighth

	//A4 eighth sharp

	//B4 eighth

	//D5 eighth

	//E5 quarter staccato (half-value)

	//G5 quarter

}



task main()
{
	playMusic();


}
