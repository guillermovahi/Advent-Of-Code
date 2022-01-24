#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define input_file "input.txt"
#define input_lines 100
#define n_columns 100

int check_corners(int array_input[input_lines][n_columns], int i, int j);
int check_borders(int array_input[input_lines][n_columns], int i, int j);
int check_rest(int array_input[input_lines][n_columns], int i, int j);

void file_to_array(int array_input[input_lines][n_columns]);

int main(void)
{
	int array_input[input_lines][n_columns];
	int star1 = 0;
	file_to_array(array_input);


	for(int i = 0; i < input_lines; i++)
	{
		for(int j = 0; j < n_columns; j++)
		{
			if (check_corners(array_input, i, j) == 1)
				star1 += array_input[i][j] + 1;
			else if (check_borders(array_input, i, j) == 1)
				star1 += array_input[i][j] + 1;
			else if (check_rest(array_input, i, j) == 1)
				star1 += array_input[i][j] + 1;
		}
	}

	for(int i = 0; i < input_lines; i++)
	{
		for(int j = 0; j < n_columns; j++)
			printf("%d", array_input[i][j]);
		printf("\n");
	}
	printf("--------------\n");
	
	printf("INPUT FOR STAR 1: %d\n", star1); // 244 too low
	return 0;
}

int check_rest(int array_input[input_lines][n_columns], int i, int j)
{
	if (i != 0 && i != (input_lines - 1) && j != 0 && j != (n_columns - 1)) //Arriba
	{
		if ((array_input[i][j+1] > array_input[i][j]) && (array_input[i][j-1] > array_input[i][j]) && (array_input[i+1][j] > array_input[i][j]) && (array_input[i-1][j] > array_input[i][j]))
			return 1;
	}
	return 0;
}

int check_borders(int array_input[input_lines][n_columns], int i, int j)
{
	if (i == 0 && j != 0 && j != (n_columns - 1)) //Arriba
	{
		if ((array_input[i][j+1] > array_input[i][j]) && (array_input[i][j-1] > array_input[i][j]) && (array_input[i+1][j] > array_input[i][j]))
			return 1;
	}
	else if (i == (input_lines - 1) && j != 0 && j != (n_columns - 1)) //Abajo
	{
		if ((array_input[i][j+1] > array_input[i][j]) && (array_input[i][j-1] > array_input[i][j]) && (array_input[i-1][j] > array_input[i][j]))
			return 1;
	}
	else if (j == 0 && i != 0 && i != (input_lines - 1)) // Izquierda
	{
		if ((array_input[i-1][j] > array_input[i][j]) && (array_input[i+1][j] > array_input[i][j]) && (array_input[i][j+1] > array_input[i][j]))
			return 1;
	}
	else if (j == (n_columns - 1) && i != 0 && i != (input_lines - 1)) // Derecha
	{
		if ((array_input[i-1][j] > array_input[i][j]) && (array_input[i+1][j] > array_input[i][j]) && (array_input[i][j-1] > array_input[i][j]))
			return 1;
	}
	return 0;
}

int check_corners(int array_input[input_lines][n_columns], int i, int j)
{
	if (i == 0 && j == 0) //Arriba izquierda
	{
		if ((array_input[i][j+1] > array_input[i][j]) && (array_input[i+1][j] > array_input[i][j]) && (array_input[i+1][j+1] > array_input[i][j]))
			return 1;
	}
	else if (i == (input_lines - 1) && j == 0) //Abajo izquierda
	{
		if ((array_input[i][j+1] > array_input[i][j]) && (array_input[i-1][j] > array_input[i][j]) && (array_input[i-1][j+1] > array_input[i][j]))
			return 1;
	}
	else if (i == 0 && j == (n_columns - 1)) //Arriba derecha
	{
		if ((array_input[i][j-1] > array_input[i][j]) && (array_input[i+1][j] > array_input[i][j]) && (array_input[i+1][j-1] > array_input[i][j]))
			return 1;
	}
	else if (i == (input_lines - 1) && j == (n_columns - 1)) //Abajo derecha
	{
		if ((array_input[i][j-1] > array_input[i][j]) && (array_input[i-1][j] > array_input[i][j]) && (array_input[i-1][j-1] > array_input[i][j]))
			return 1;
	}
	return 0;
}

void file_to_array(int array_input[input_lines][n_columns])
{
	FILE *my_input = fopen(input_file, "r");
	int i = 0, j = 0;
	char c;
	while(fscanf(my_input, "%c", &c) != EOF)
	{
		if(c == '\n')
		{
			fscanf(my_input, "%c", &c);
			i++;
			j = 0;
		}
		array_input[i][j++] = atoi(&c);
	}
}