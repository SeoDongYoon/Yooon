#include <stdio.h>
#include <wiringPi.h>

#define wPi_22 22

int main(int n, char * s[])
{
	//if(n<2)
	//{
		//sscanf(s[1], "%d", &dr);		// sscanf에서  맨 앞의 s는 string(문자열)을 의미한다.
		//drh = (dr * period) / 100;
		//drl = period - drh;
		//return drl;
	//}
	//else
	//{	
		//sscanf(s[1], "%d", &dr);		// sscanf에서  맨 앞의 s는 string(문자열)을 의미한다.
		//drh = (dr * period) / 100;
		//drl = period - drh;
		//wiringPiSetup();		// wPi Pin numbering
	//}
	if(n<2)
	{
		printf("usage : pwm1 [duty_rate(%%)] [[period]] \n\n");
		printf("	period = 10 ms if empty\n\n");
		return 1;
	}
	int dr, drh, drl, period = 10;
	sscanf(s[1], "%d", &dr);
	
	if(n>2) sscanf(s[2],"%d",&period);
	drh = (dr * period) / 100;
	drl = period - drh;
	wiringPiSetup();
	
	pinMode(wPi_22, OUTPUT);
	for(int i = 0; i<500; i++)
	{
		digitalWrite(wPi_22, 1);
		delay(drh);
		digitalWrite(wPi_22, 0);
		delay(drl);
	}
	return 0;
}
