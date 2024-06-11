#include <stdio.h>				// 
#include <wiringPi.h>
#include <stdlib.h>
#include <signal.h>

#define RED 	8
#define GREEN	9
#define YELLOW	7
#define SW		2
#define SSW		3

int mode = 0;
int intv = 0;					// 0 ~ 8 (0~900ms 시간 설정을 위한 세팅)
int tim;						// delay 시간 늘려주는 변
int ps[40];						// pin number : 40, pin status : default 0

void Toggle(int pin)
{
	ps[pin] =!ps[pin];
	digitalWrite(pin,ps[pin]);
}

void gpioisr()
{
	if(++intv > 8) intv = 0;	// 0 ~ 9 (0~900ms 시간 설정을 위한 세팅)
	printf("GPIO interrupt occured....\n");
}

void gpioStop()
{
	printf("STOP!!\n");
	digitalWrite(RED, LOW);
	digitalWrite(GREEN, LOW);
	digitalWrite(YELLOW, LOW);
	exit(0);
}


int main()
{
	wiringPiSetup();			// 어떤  핀을 In Out으로 사용할지 세팅
	pinMode(RED, OUTPUT);			// 8,9,7 out, 2 : in
	pinMode(GREEN, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(SW, INPUT);
	wiringPiISR(SW, INT_EDGE_FALLING, gpioisr);
	wiringPiISR(SSW, INT_EDGE_FALLING, gpioStop);
	
	
	for(;;)
	{	
		tim = (9-intv)*100;		// 0 ~ 9 (0~900ms 시간 설정을 위한 세팅)
		if(mode)
		{
			Toggle(8); delay(tim);
			Toggle(9); delay(tim);
			Toggle(7); delay(tim);
		}
		else
		{
			Toggle(7); delay(tim);
			Toggle(9); delay(tim);
			Toggle(8); delay(tim);
		}
	}
	return 0;
}
