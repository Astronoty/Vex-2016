
void playMusic()
{
	//cuttime
	playTone(698.46, 100); //F5 half
	//wait10Msec();

	playTone(783.99, 50); //G5 quarter
	//wait10Msec(.5);

	playTone(783.99, 50); //G5 quarter
	//wait10Msec(.5);

	playTone(659.25, 25); //E5 eighth
	//wait10Msec(.25);

	playTone(587.33, 25);//D5 eighth
	//wait10Msec(.25);

	playTone(466.16, 25);//A4 eighth sharp
	//wait10Msec(.25);

	playTone(493.88, 25);//B4 eighth
	//wait10Msec(.25);

	playTone(587.33, 25);//D5 eighth
	//wait10Msec(.25);

	playTone(493.88, 25);//B4 eighth
	//wait10Msec(.25);

	playTone(659.25, 50); //E5 quarter
	//wait10Msec(.5);

	playTone(587.33, 25);//D5 eighth
	//wait10Msec(.25);

	playTone(493.88, 25);//B4 eighth
	//wait10Msec(.25);

	playTone(440.00, 25);//A4 eighth
	//wait10Msec(.25);

	playTone(392.00, 25);//G4 eighth
	//wait10Msec(.25);

	playTone(392.00, 50);//G4 quarter
	//wait10Msec(.5);

	playTone(392.00, 25);//G4 eighth
	//wait10Msec(.25);

	playTone(493.88, 50);//B4 eighth tied eighth = quarter
	//wait10Msec(.5);

	playTone(587.33, 25);//D5 eighth
	//wait10Msec(.25);

	playTone(659.25, 25); //E5 eighth
	//wait10Msec(.25);

	playTone(587.33, 25);//D5 eighth
	//wait10Msec(.25);

	playTone(783.99, 50); //G5 quarter
	//wait10Msec(.5);





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
