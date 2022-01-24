#include <stdio.h>
#include <stdlib.h>

long int new_elements(long int **evolution, long int elements, int i);
void modify_evolution(long int **evolution, long int elements, long int before_elements, int i);

int main(void)
{
	int initial_ages = 0;
	char c;
	FILE *my_input = fopen("input.txt", "r");
	while((c = fgetc(my_input)) != '\n')
	{	
		if (c != ',')
			initial_ages++;
	}
	//printf("initial ages: %d",initial_ages);
	fclose(my_input);
	
	//Meto en un array 2D la evolución de la especie
	long int **evolution = (long int **) malloc(257 *sizeof(long int *));
	long int i = 0, j = 0;
	my_input = fopen("input.txt", "r");
	evolution[0] = (long int *) malloc(initial_ages * sizeof(long int));
	while((c = fgetc(my_input)) != '\n')
	{	
		if (c != ',')
			evolution[i][j++] = atoi(&c);
	}
	fclose(my_input);
	
	long int elements = initial_ages;
	long int add_elements, before_elements;
	int star1;
	while(i < 256)
	{
		add_elements = new_elements(evolution, elements, i);
		//free(evolution[i]);
		before_elements = elements;
		elements += add_elements;
		/* if (i == 79)
			star1 = elements; */
		printf("%ld: | elements: %ld| dif:%ld\n",i, elements, add_elements);
		evolution[++i] = (long int *) malloc(elements * sizeof(long int));
		modify_evolution(evolution, elements, before_elements, i);
		//printf("After %d day:\t", i);
		
		
	}
	printf("----------\n");
	printf("%d: %ld\n",i, elements);
	printf("INPUT FOR STAR 1: %d\n", star1);
	
	
	return 0;
}

void modify_evolution(long int **evolution, long int elements, long int before_elements, int i)
{
	int j;
	for(j = 0; j < elements; j++)
	{	
		if (j >= before_elements)
			evolution[i][j] = 8;
		else
		{
			if(evolution[i-1][j] == 0)
				evolution[i][j] = 6;
			else
				evolution[i][j] = evolution[i-1][j] - 1;
		}
	} 
}

long int new_elements(long int **evolution, long int elements, int i)
{
	long int add_elements = 0, j;
	for(j = 0; j < elements; j++)
	{		
		if (evolution[i][j] == 0)
			add_elements++;
	}
	return add_elements;
}
	