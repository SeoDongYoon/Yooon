#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define wPi_22 22

int main(int n, char * s[])
{
	if(n<2)
	{
		printf("usage : pwm2 [duty_rate(%%)] [[period]] \n\n");
		printf("	period = 10 ms if empty\n\n");
		return 1;
	}
	int dr, drh, drl ,period = 10;
	sscanf(s[1], "%d", &dr);
	
	if(n>2) sscanf(s[2],"%d",&period);
	drh = (dr * period) / 100;	// Mark time 
	drl = period - drh;			// Space time
	
	wiringPiSetup();
	pinMode(wPi_22, OUTPUT);
	
	pwmSetMode(PWM_MODE_MS);	// pwm방식을 Mark & Space라고 한다.
	softPwmCreate(wPi_22, drh, period);
	// softPwmWrite(wPi_22, 70);
	
	delay(5000);
	softPwmStop(wPi_22);
	
	return 0;
}
