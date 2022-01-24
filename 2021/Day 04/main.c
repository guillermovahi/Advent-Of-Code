#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minus_one_table(int table[5][5], int number_orders[100], int actual_n);
void new_table(int table[5][5], int max_table[100][5][5], int n_table);
int check_row_or_column(int table[5][5]);
int check_first_line(int line_sing[100]);
int check_last_line(int line_sing[100]);

int main(void)
{
	int num, i = 0, j = 0, k, l, z = 0, x, y;
	int table[5][5];
	int max_table[100][5][5];
	int number_orders[100]; //Del 0 al 99
	int line_sing[100];
	char *str1, *token;
	char line[290];

	scanf("%s",&line);
	
	for (i = 0, str1 = line; ;i++, str1 = NULL) {
        token = strtok(str1, ",");
        if (token == NULL)
            break;
		number_orders[i] = atoi(token);
		//printf("%d|",number_orders[i]);
    }
	
	int time_sing_min = 100;
	int time_sing_max = 0;

	for(i = 0; i < 100; i++)
	{
		new_table(table, max_table, i); //tenemos nuevo tablero
	
		for(j = 0; j < 100; j++) // comprobar los valores del array con el orden de numeros hasta acabar
		{
			//Buscar number_orders[j] en todo el tablero
			minus_one_table(table, number_orders, j);
			if (check_row_or_column(table) == 1)
			{
				line_sing[z] = j;
				//meter en la 3matriz el tablero cuando canto linea
				x = -1;
				while(++x < 5)
				{
					y = -1;
					while(++y < 5)
						max_table[z][x][y] = table[x][y];
				}
				z++;
				time_sing_min = time_sing_min > j ? j : time_sing_min;
				time_sing_max = time_sing_max < j ? j : time_sing_max;

				//printf("Carton %d: %d\n", i, j);
				break;
			}	
		}		
	}

	int not_yet_first_sum = 0;
	int not_yet_last_sum = 0;
	int fastest_table = check_first_line(line_sing);
	int latest_table = check_last_line(line_sing);

	printf("%d | %d\n", fastest_table, latest_table);
	/* printf("------\n");
	printf("NUMEROS QUE TARDAN EN CANTAR LINEAS ------------------\n");
 */
	/* k = -1;
	while(++k < 100)
		printf("%d: %d\n", k, line_sing[k]);

 */
	k = -1;
	while(++k < 5)
	{
		j = -1;
		while(++j < 5)
		{
			//printf("%d ", max_table[latest_table][k][j]);
			if (max_table[fastest_table][k][j] != -1)
				not_yet_first_sum += max_table[fastest_table][k][j];
			
			if (max_table[latest_table][k][j] != -1)
				not_yet_last_sum += max_table[latest_table][k][j];
		}
	}
	/* printf("ORDEN DE SALIDA DE NUMEROS ------------------\n");
	k = -1;
	while(++k < 100)
		printf("%d: %d\n", k, number_orders[k]); */

	int star1, star2;

	star1 = not_yet_first_sum * number_orders[time_sing_min];
	star2 = not_yet_last_sum * number_orders[time_sing_max];
	printf("INPUT FOR STAR 1: %d\n", star1);
	printf("INPUT FOR STAR 2: %d\n", star2);


	i = -1;
	while(++i < 5) //Comprobamos filas
	{
		j = -1;
		while(++j < 5)
			printf("%d ", max_table[14][i][j]);
		printf("\n");
	}


	return 0;
}

int check_first_line(int line_sing[100])
{
	int i, min_value = line_sing[0], min_sing;
	for(i = 0; i < 100; i++)
	{
		if(line_sing[i] < min_value)
		{
			min_value = line_sing[i];
			min_sing = i;
		}
	}
	return min_sing;
}

int check_last_line(int line_sing[100])
{
	int i, max_value = line_sing[0], max_sing;
	for(i = 0; i < 100; i++)
	{
		if(line_sing[i] > max_value)
		{
			max_value = line_sing[i];
			max_sing = i;
		}
	}
	return max_sing;
}


int check_row_or_column(int table[5][5]) //Si encuentra una línea o una columna llena de -1, se canta línea
{
	int i, j, sumfil = 0, sumcol = 0;
	i = -1;
	while(++i < 5) //Comprobamos filas
	{
		j = 0;
		while(table[i][j] == -1)
			j++;
		if (j == 5)
			return 1;
	}
	j = -1;
	while(++j < 5) //Comprobamos columnas
	{
		i = 0;
		while(table[i][j] == -1)
			i++;
		if (i == 5)
			return 1;
	}
	
	
	return 0;
}

void minus_one_table(int table[5][5], int number_orders[100], int actual_n)
{
	int i, j;
	i = -1;
	while(++i < 5)
	{
		j = -1;
		while(++j < 5)
		{
			if(number_orders[actual_n] == table[i][j])
				table[i][j] = -1;
		}
	}
}

void new_table(int table[5][5], int max_table[100][5][5], int n_table)
{
	int i = -1, j, num;
	while(++i < 5)
	{
		j = -1;
		while(++j < 5)
		{
			scanf("%d", &num);
			table[i][j] = num;
			max_table[n_table][i][j] = num;
		}
			
	}	
}
