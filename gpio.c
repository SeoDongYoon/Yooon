#include <stdio.h>
#include <wiringPi.h>

int ps[40];						// pin number : 40, pin status : default 0
void Toggle(int pin)
{
	ps[pin] =!ps[[in]
	digitalWrite(pin,ps[pin]);
}

int main()
{
	wiringPiSetup();			// 어떤  핀을 In Out으로 사용할지 세팅
	pinMode(8, OUTPUT);			// 8,9,7 out, 2 : in
	pinMode(9, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(2, INPUT);
	int mode = 0;
	
	for(int i=0;i<10;i++)
	{	
		if(mode)
		{
			Toggle(8); delay(200);
			Toggle(9); delay(200);
			Toggle(7); delay(200);
		}
		else
		{
			Toggle(7); delay(200);
			Toggle(9); delay(200);
			Toggle(8); delay(200);
		}
		if(digitalRead(2) == 0)
		{
			mode = !moed
		}
	}
	return 0;
}
