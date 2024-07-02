#include <stdio.h>
#include <wiringPi.h>		
#include <wiringPiI2C.h>

int main()
{
	int fd = wiringPiI2CSetup(0x48);	// Device reset

	int x,y;
	// float f,f2;
	
	while(1)
	{
		
		wiringPiI2CWrite(fd, 00);		// ch00 (PR) select
		x = (wiringPiI2CRead(fd) * 80) / 255;
		// f = x * 80 / 255;
		delay(100);
		
		wiringPiI2CWrite(fd, 01);		// ch01 (TR) select
		y = (wiringPiI2CRead(fd) * 24) / 255;
		// f2 = y * 80 / 255;
		delay(100);
		
		// printf("\033[2J");		// \033에서 0 으로 시작하는것은 octal을 의미한다. 8진수
								// [2j 는 화면 클리어를 시키기 위한 시퀀스
								// \033 ESC
		printf("\033[%d;%dH(%d,%d)\n", y,x,x,y);	// [x;yH	
		//delay(100);
		
	}
	return 0;
}
