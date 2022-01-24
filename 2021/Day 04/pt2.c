#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimir_matrices(int matrix[100][5][5]);
void rellenar_matrices(int matrix[100][5][5], int number_order[100]);
int check_row_or_column(int table[100][5][5], int k); //Si encuentra una línea o una columna llena de -1, se canta línea
int time_line_is_signed(int matrix[100][5][5], int n_table, int number_order[100]);
void assign_fastest(int matrix[100][5][5], int iteracion_de_linea[100],int number_order[100], int min[2]);
void assign_slowest(int matrix[100][5][5], int iteracion_de_linea[100],int number_order[100], int max[2]);


int main(void)
{
	int number_order[100];
	int matrix[100][5][5];
	int iteracion_de_linea[100];
	int min[2], max[2];
	rellenar_matrices(matrix, number_order);
	//imprimir_matrices(matrix);
	//printf("HOLA");
	for (int i = 0; i < 100; i++)
		iteracion_de_linea[i] = time_line_is_signed(matrix, i, number_order);
		
	assign_fastest(matrix, iteracion_de_linea, number_order, min);
	assign_slowest(matrix, iteracion_de_linea, number_order, max);

	for (int n = 0; n < 1; n++)
	{
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5; j++)
			{
				if( matrix[66][i][j] == number_order[n])
					matrix[66][i][j] = -1;
				if (check_row_or_column(matrix, 66) == 1)
					break;
			}
		}
	}
	int sum_tot = 0;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if (matrix[14][i][j] != -1)
				sum_tot += matrix[14][i][j];
		}
	}
	printf("sumtot: %d | ultima bola: %d\n", sum_tot, number_order[85]);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
			printf("%d\t",matrix[14][i][j]);
		printf("\n");
	}
	printf("1: %d 2: %d 3: %d\n", iteracion_de_linea[0], iteracion_de_linea[1], iteracion_de_linea[2]);
	printf("Carton mas rapido: %d | movs: %d\nCarton mas lento: %d | movs: %d\n", min[0], min[1], max[0], max[1]);
	printf("2394 es too high");
	return 0;
}

void assign_fastest(int matrix[100][5][5], int iteracion_de_linea[100],int number_order[100], int min[2])
{
	min[1] = iteracion_de_linea[0];	
	for (int i = 0; i < 100; i++)
	{
		if (iteracion_de_linea[i] < min[1])
		{
			min[0] = i;
			min[1] = iteracion_de_linea[i];
		}
	}
}

void assign_slowest(int matrix[100][5][5], int iteracion_de_linea[100],int number_order[100], int max[2])
{
	max[1] = iteracion_de_linea[0];	
	for (int i = 0; i < 100; i++)
	{
		if (iteracion_de_linea[i] > max[1])
		{
			max[0] = i;
			max[1] = iteracion_de_linea[i];
		}
	}
}

int time_line_is_signed(int matrix[100][5][5], int n_table, int number_order[100])
{
	int i, j, k, n = -1;

	for (n = 0; n < 100; n++)
	{
		for(j = 0; j < 5; j++) // Recorro la matriz buscando todos los numeros
		{
			for(k = 0; k < 5; k++)
			{
				if( matrix[n_table][j][k] == number_order[n])
					matrix[n_table][j][k] = -1;
				if (check_row_or_column(matrix, n_table) == 1)
					return n;
			}
		}
	}
	return 300;
}

int check_row_or_column(int table[100][5][5], int k) //Si encuentra una línea o una columna llena de -1, se canta línea
{
	int i, j, sumfil = 0, sumcol = 0;
	i = -1;
	while(++i < 5) //Comprobamos filas
	{
		j = 0;
		while(table[k][i][j] == -1)
			j++;
		if (j == 5)
			return 1;
	}
	j = -1;
	while(++j < 5) //Comprobamos columnas
	{
		i = 0;
		while(table[k][i][j] == -1)
			i++;
		if (i == 5)
			return 1;
	}
	return 0;
}

void rellenar_matrices(int matrix[100][5][5], int number_order[100])
{
	FILE *my_input = fopen("input.txt", "r");
	int i = -1, j, num, a, b, c, d, e;

	while(++i < 100)
	{
		fscanf(my_input, "%d,", &num);
		number_order[i] = num;
	}
	
	i = -1;
	while(++i < 100)
	{
		for(j = 0; j < 5; j++)
		{
			fscanf(my_input, "%d %d %d %d %d", &a, &b, &c, &d, &e);
			matrix[i][j][0] = a;
			matrix[i][j][1] = b;
			matrix[i][j][2] = c;
			matrix[i][j][3] = d;
			matrix[i][j][4] = e;
		}
	}
}

void imprimir_matrices(int matrix[100][5][5])
{
	int i, j, k;
	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 5; j++)
		{
			for(k = 0; k < 5; k++)
				printf("%d\t", matrix[i][j][k]);
			printf("\n");
		}
		printf("----------------------------------\n");
	}
}
