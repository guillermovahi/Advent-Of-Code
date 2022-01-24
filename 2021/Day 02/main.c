#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i = 0, j = 0, forward = 0, down = 0, up = 0, aim = 0, depth = 0, star1, star2;
	char line[10];
	int num;
	int *arr_num = (int *) malloc(1000 * sizeof(int));
	char **arr_dir = (char **) malloc(1000 * sizeof(char *));
	
	for (i = 0; i < 1000; i++)
	{
		arr_dir[i] = (char *) malloc( 10 * sizeof(char));
		if (arr_dir[i] == NULL)
			exit(71);
	}	
	
	i = -1;
	while( ++i < 1000)
	{	
		scanf("%s", &line);
		arr_dir[i] = strdup(line);
		scanf("%d", &num);
		arr_num[i] = num;
	}
	
	j = -1;
	while(++j < 1000 )
	{
		if (strcmp(arr_dir[j],"forward") == 0)
		{
			forward += arr_num[j];
			aim += arr_num[j] * depth;
		}		
		else if (strcmp(arr_dir[j],"down") == 0)
		{
			down += arr_num[j];	
			depth += arr_num[j];
		}
		else
		{
			up += arr_num[j];
			depth -= arr_num[j];
		}
	}

	star1 = forward * (down - up);
	star2 = forward * aim;
	printf("INPUT FOR STAR 1: %d\n", star1);
	printf("INPUT FOR STAR 2: %d\n", star2);

	return 0;
}