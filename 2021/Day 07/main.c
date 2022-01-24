#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *my_input = fopen("input.txt", "r");
	int num, initial_nums = 1, i = -1, j, k;
	int horizontal_position = 0, min_fuel = 0, new_fuel = 0;
	int list_of_horizontal_position[1000];
	char c;
	while((c = fgetc(my_input)) != '\n')
	{	
		if (c == ',')
			initial_nums++;
	}
	//printf("initial ages: %d",initial_ages);
	fclose(my_input);
	my_input = fopen("input.txt", "r");
	while(++i < initial_nums)
	{
		fscanf(my_input, "%d,", &num);
		//printf("%d\n",num);
		list_of_horizontal_position[i] = num;
		num = 0;
		for(k = 1; k <= abs(list_of_horizontal_position[i] - i); k++)
			num += k;
		min_fuel += num;
	}
	fclose(my_input);
	i = 0;
	while(++i < initial_nums)
	{
		j = -1;
		new_fuel = 0;		
		while(++j < initial_nums)
		{
			num = 0;
			for(k = 1; k <= abs(list_of_horizontal_position[j] - i); k++)
				num += k;
			new_fuel += num;
		}
		if((new_fuel < min_fuel) && new_fuel > 0)
			min_fuel = new_fuel;
	}
	printf("min_fuel:%d new_fuel: %d\n", min_fuel, new_fuel); //3633971 too low
	return 0;
}	