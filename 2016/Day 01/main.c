#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{

	int star1 = 0;
	int move;
	int orientation = 0;
	int coordX = 0, coordY = 0;
	char rotation;
	
	int it = 0;
	while(scanf("%c%d, ", &rotation, &move) != EOF)
	{
		if (orientation == 0)
		{
			if (rotation == 'R')
				orientation = 90;
			else
				orientation = 270;
		}
		else if (orientation == 90)
		{
			if (rotation == 'R')
				orientation = 180;
			else
				orientation = 0;
		}
		else if (orientation == 180)
		{
			if (rotation == 'R')
				orientation = 270;
			else
				orientation = 90;
		}
		else if (orientation == 270)
		{
			if (rotation == 'R')
				orientation = 0;
			else
				orientation = 180;
		}

		
		if (orientation == 90)
			coordX += move;
		else if(orientation == 270)
			coordX -= move;
		else if(orientation == 0)
			coordY += move;
		else if(orientation == 180)
			coordY -= move;
		
	}
	star1 = abs(coordX + coordY);
	printf("STAR 1: %d\n", star1); 

	return 0;
}