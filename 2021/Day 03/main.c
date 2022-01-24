#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char **copy_matrix(char **matrix_orig, int num_values)
{
	int i = 0;
	char **matrix_copy;
	matrix_copy = (char **) malloc(num_values * sizeof(char *));

	while(i < num_values)
	{
		matrix_copy[i] = (char *) malloc( 13 * sizeof(char));
		matrix_copy[i] = strdup(matrix_orig[i++]);	
	}	
	return matrix_copy;
}

int o2_num(char **arr)
{
	int i = 0, k = 0, j = 0, zero = 0, one = 0, num_new_lines, m, n, o2_num = 0;
	char number;
	char **arr_aux = copy_matrix(arr, 1000);
	i = 1000;
	while(k < 12)
	{	
		j = 0;
		zero = 0;
		one = 0;
		while(j < i) // La i tiene que ser el número de lineas a evaluar
		{
			if(arr[j][k] == '0')
				zero++;
			else
				one++;
			j++;
		}
		//printf("IT: %d | UNOS: %d | CEROS: %d\n",k, one, zero);
		
		arr_aux = copy_matrix(arr, i);
		num_new_lines = zero > one ? zero : one;
		//printf("new_lines: %d\n", num_new_lines);
		number = zero > one ? '0' : '1';
		arr = realloc(arr, num_new_lines * sizeof(char *));
		m = -1;
		n = 0;
		while(++m < num_new_lines)
		{
			while(arr_aux[n][k] != number && n < i)
				n++;
			arr[m] = strdup(arr_aux[n++]);
			//printf("%d: %s\n\n", m,arr[m]);
		}
		i = num_new_lines;
		if (i == 1)
		{
			//printf("BYNARY OXYGEN NUMBER: %s\n", arr[m]);
			i = 12;
			j = 0;
			while(--i > -1)
			{
				if(arr[0][i] == '1')
					o2_num += pow(2, j);
				j++;
			}
			//printf("DECIMAL OXYGEN NUMBER: %d\n", o2_num);
		}
			
		k++;
	}
	return o2_num;
}

int co2_num(char **arr)
{
	int i = 0, k = 0, j = 0, zero = 0, one = 0, num_new_lines, m, n, co2_num = 0;
	char number;
	char **arr_aux = copy_matrix(arr, 1000);
	i = 1000;
	while(k < 12)
	{	
		j = 0;
		zero = 0;
		one = 0;
		while(j < i) // La i tiene que ser el número de lineas a evaluar
		{
			if(arr[j][k] == '0')
				zero++;
			else
				one++;
			j++;
		}
		//printf("IT: %d | UNOS: %d | CEROS: %d\n",k, one, zero);
		arr_aux = copy_matrix(arr, i);
		num_new_lines = zero > one ? one : zero;
		//printf("new_lines: %d\n", num_new_lines);
		number = zero > one ? '1' : '0';
		arr = realloc(arr, num_new_lines * sizeof(char *));
		m = -1;
		n = 0;
		while(++m < num_new_lines)
		{
			while(arr_aux[n][k] != number && n < i)
				n++;
			arr[m] = strdup(arr_aux[n++]);
			//printf("%d: %s\n\n", m,arr[m]);
		}
		i = num_new_lines;
		if (i == 1)
		{
			//printf("BYNARY CO2 NUMBER: %s\n", arr[m]);
			i = 12;
			j = 0;
			while(--i > -1)
			{
				if(arr[0][i] == '1')
					co2_num += pow(2, j);
				j++;
			}
			//printf("CO2 OXYGEN NUMBER: %d\n", co2_num);
		}
			
		k++;
	}
	return co2_num;
}

int main(void)
{
	int num, i = 0, j = 0, k = 0;
	int zero = 0, one = 0;
	char gamma_rate[13];
	char epsilon_rate[13];
	
	char oxygen_rate[13];
	char co2_rate[13];

	int nums_to_evaluate = 0;
	int gamma_num = 0, epsilon_num = 0;

	int star1, star2;
	char line[13];
	char **arr = (char **) malloc(1000 * sizeof(char *));
	char **arr_aux;
	int num_new_lines;
	int m,n, o2, co2;
	char number;
	for (i = 0; i < 1000; i++)
	{
		arr[i] = (char *) malloc( 13 * sizeof(char));
		if (arr[i] == NULL)
			exit(71);
	}
	i = 0;
	while(scanf("%s", &line) && i < 1000)
		arr[i++] = strdup(line);

	while(k < 12)
	{
		if(arr[j][k] == '0')
			zero++;
		else
			one++;
		j++;
		if (j == i)
		{
			//printf("ITER: %d | 1: %d | 0: %d\n",k,one,zero);
			gamma_rate[k] = zero < one ? '1' : '0' ;
			epsilon_rate[k] = zero < one ? '0' : '1'; 
			j = 0;
			k++;
			zero = 0;
			one = 0;
		}
	}
	gamma_rate[12] = '\0';
	epsilon_rate[12] = '\0';

	i = 12;
	j = 0;
	while(--i > -1)
	{
		if(gamma_rate[i] == '1')
			gamma_num += pow(2, j);

		if(epsilon_rate[i] == '1')
			epsilon_num += pow(2, j);
		j++;
	}

	arr_aux = copy_matrix(arr, 1000);
	
	printf("-----------------------------\n");
	star1 = gamma_num * epsilon_num;
	printf("INPUT FOR STAR 1: %d\n", star1);
	
	printf("-----------------------------\n");
	o2 = o2_num(arr);
	co2 = co2_num(arr_aux);
	star2 = o2 * co2;
	printf("INPUT FOR STAR 2: %d\n", star2);	
	return 0;
}