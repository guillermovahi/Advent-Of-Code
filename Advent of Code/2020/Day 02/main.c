#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	FILE *the_file = fopen("input.txt", "r");
	if (the_file == NULL)
	{
		perror("Unable to open the file");
		exit(1);
	}
	int min, max;
	char *character;
	char pass[40];
	char line[200];
	char *token;
	int i = 0;
	while(fgets(line, sizeof(line), the_file) && i++ < 1)
	{
		token = strtok(line, " -:");
		min = atoi(token);
		token = strtok(NULL, " -:");
		max = atoi(token);
		character = strtok(NULL, " -:");
		/* 
		while(token != NULL)
		{
			printf("%s",token);
			printf("B-");
			token = strtok(NULL, " -:");
			
			printf("%s",token);
			printf("C-");
		}
		printf("\n"); */
	}

	printf("MIN: %d | MAX: %d | CHAR: %s | TOKEN: %s", min, max, character, token);
	return 0;
}