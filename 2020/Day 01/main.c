#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *archivo = fopen(argv[1], "r");
	char line[5];
	int array_of_ints[200];
	int i, j, k, l, num, res1, res2;

	i = 0;
	while(fgets(line, 6, archivo) != NULL)
	{
		num = atoi(line);
		array_of_ints[i++] = num;
	}
	fclose(archivo);
	
	j = 0;
	//Bucle estrella 1
	while(j < i)
	{
		k = j + 1;
		while(k < i)
		{
			if ((array_of_ints[j] + array_of_ints[k]) == 2020)
				res1 = array_of_ints[j] * array_of_ints[k];
			k++;
		}
		j++;
	}	
	
	j = 0;
	//Bucle estrella 2
	while(j < i)
	{
		k = j + 1;
		while(k < i)
		{
			l = j + 2;
			while(l < i)
			{
				if ((array_of_ints[j] + array_of_ints[k] + array_of_ints[l]) == 2020)
				res2 = array_of_ints[j] * array_of_ints[k] * array_of_ints[l];
				l++;
			}
			k++;
		}
		j++;
	}	

	printf("Star 1: %d\n",res1);
	printf("Star 2: %d\n",res2);

	return 0;
}