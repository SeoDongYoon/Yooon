#include <stdio.h>

int main()
{
	int x = 10, int y = 20;
	printf("\033[2J");
	while(1)
	{
		printf("\033[%d;%dH@", x, y);
	}
	return 0;
}
