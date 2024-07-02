#include <stdio.h>
#include <wiringPi.h>		
#include <wiringPiI2C.h>

main()
{
	int fd = wiringPiI2CSetup(0x48);	// Device reset

	int v1,v2,v3;
	float f,f2,f3;
	
	while(1)
	{
		
		wiringPiI2CWrite(fd, 00);		// ch00 (PR) select
		v1 = wiringPiI2CRead(fd);
		f = (float)((v1/255.0)*5.0);
		delay(100);
		
		wiringPiI2CWrite(fd, 01);		// ch01 (TR) select
		v2 = wiringPiI2CRead(fd);
		f2 = (float)((v2/255.0)*5.0);
		delay(100);
		
		wiringPiI2CWrite(fd, 03);		// ch03 (VR) select
		v3 = wiringPiI2CRead(fd);
		f3 = (float)((v3/255.0)*5.0);
		printf("ADC input level = %d %d %d(%4.1fv %4.1f %4.1f)\n",v1,v2,v3,f,f2,f3);
		delay(500);
	}
}
