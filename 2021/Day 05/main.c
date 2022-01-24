#include <stdio.h>
#include <stdlib.h>

void diagonal_move(int **map, int x1, int y1, int x2, int y2);
void vertical_move(int **map, int x1, int y1, int x2, int y2);
void horizontal_move(int **map, int x1, int y1, int x2, int y2);

int main(void)
{
	int **map = (int **) malloc(1000 * sizeof(int *));
	int i, j;
	
	//Reservo memoria al mapa
	for(i = 0; i < 1000; i++)
		map[i] = (int *) malloc(1000 * sizeof(int));

	
	//Relleno el mapa de ceros
	for(i = 0; i < 1000; i++)
	{
		for(j = 0; j < 1000; j++)
			map[i][j] = 0;
	}
	
	FILE *my_input = fopen("input.txt", "r");
	int x1, y1, x2, y2;

	i = -1;
	while(++i < 500)
	{
		fscanf(my_input, "%d,%d -> %d,%d", &x1, &y1, &x2, &y2);
		if ((abs(x1 - y1) == abs(x2 - y2)) || ((x1 + y1) == (x2 + y2)))
			diagonal_move(map, x1, y1, x2, y2);
		else
		{
			if(x1 == x2)
			vertical_move(map, x1, y1, x2, y2);	
			if(y1 == y2)
			horizontal_move(map, x1, y1, x2, y2);		
		}
				
	}
	fclose(my_input);

	/* for(i = 0; i < 1000; i++)
	{
		for(j = 0; j < 1000; j++)
		{
			if(map[i][j] != 0)
				printf("%d",map[i][j]);
			else
				printf(".");
		}
		printf("\n");
	} */

	int number_of_2 = 0;
	for(i = 0; i < 1000; i++)
	{
		for(j = 0; j < 1000; j++)
		{
			if(map[i][j] >= 2)
				number_of_2++;
		}
	}

	printf("NUMBER OF 2: %d", number_of_2); // 5189 is too high  y 5357 tambien

	return 0;
}

void diagonal_move(int **map, int x1, int y1, int x2, int y2)
{
	int n_times, j, aux, auy;
	aux = x1;
	auy = y1;
	if(x1 > x2)
	{
		x1 = x2;
		y1 = y2;
		x2 = aux;
		y2 = auy;
	}
	aux = x1;
	auy = y1;
	if (y1 < y2) // hacia arriba
	{
		n_times = (x2 - x1) + 1;
		j = 0;
		while(j++ < n_times)
		{
			map[auy][aux] += 1;
			aux++;
			auy++;
		}
	}
	if (y2 < y1) //hacia abajo
	{
		n_times = (x2 - x1) + 1;
		j = 0;
		while(j++ < n_times)
		{
			map[y1][x1] += 1;
			x1++;
			y1--;
		}
	}
	/* if((x1 + x2) == (y1 + y2))// || (abs(x1-)))
	{
		n_times = (x2 - x1) + 1;
		j = 0;
		while(j++ < n_times)
		{
			map[auy][aux] += 1;
			aux++;
			auy++;
		}
	}

	if(((x1 == y2) && (y1 == x2)) || ((x1 + y1) == (x2 + y2)))
	{
		n_times = abs(x1 - x2) + 1;
		j = 0;
		while(j++ < n_times)
		{
			map[y2][x2] += 1;
			x2++;
			y2--;
		}
	} */
}


void vertical_move(int **map, int x1, int y1, int x2, int y2)
{
	int n_times, j, aux;
	aux = y1;
	if(y2 > y1)
	{
		n_times = (y2 - y1) + 1;
		j = 0;
		while(j++ < n_times)
		{
			map[aux][x1] += 1;
			aux++;
		}	
	}
	if(y1 > y2) 
	{
		n_times = (y1 - y2) + 1;
		j = 0;
		while(j++ < n_times)
		{
			map[y2][x1] += 1;
			y2++;
		}	
	}
}

void horizontal_move(int **map, int x1, int y1, int x2, int y2)
{
	int n_times, j, aux;
	aux = x1;
	if(x2 > x1)
	{
		n_times = (x2 - x1) + 1;
		j = 0;
		while(j++ < n_times)
		{
			map[y1][aux] += 1;
			aux++;
		}
	}
	if(x1 > x2)
	{
		n_times = (x1 - x2) + 1;
		j = 0;
		while(j++ < n_times)
		{
			map[y1][x2] += 1;
			x2++;
		}	
	}
}
