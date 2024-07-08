#include <stdio.h>
#include <wiringPi.h>

#define wPi_22 22
int main()
{
	
	
	wiringPiSetup();
	pinMode(wPi_22, PWM_OUTPUT);
	pwmWrite(wPi_22, 500);
	
	return 0;
}
