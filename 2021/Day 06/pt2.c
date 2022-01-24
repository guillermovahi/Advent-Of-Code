#include <stdio.h>

void initialize(long long numbers[9])
{
	char c;
	FILE *my_input = fopen("input.txt", "r");

	//Meto en un array de long long cuantos elementos de cada hay 
	while((c = fgetc(my_input)) != '\n')
	{	
		if (c == '0')
			numbers[0] += 1;
		else if(c == '1')
			numbers[1] += 1;
		else if(c == '2')
			numbers[2] += 1;
		else if(c == '3')
			numbers[3] += 1;
		else if(c == '4')
			numbers[4] += 1;
		else if(c == '5')
			numbers[5] += 1;
		else if(c == '6')
			numbers[6] += 1;
		else if(c == '7')
			numbers[7] += 1;
		else if(c == '8')
			numbers[8] += 1;
	}
	printf("0: %lld\n1: %lld\n2: %lld\n3: %lld\n4: %lld\n5: %lld\n6: %lld\n7: %lld\n8: %lld\n", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8]);
	fclose(my_input);
}

int main(void)
{
	long long numbers[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	long long poblation = 0;
	long long zero, one, two, three, four, five, six, seven, eight;
	int i = 0;
	initialize(numbers);
	poblation = numbers[0] + numbers[1] + numbers[2] + numbers[3] + numbers[4] + numbers[5] + numbers[6] + numbers[7] + numbers[8];
	while(i++ < 256)
	{
		zero = numbers[0];
		one = numbers[1];
		two = numbers[2];
		three = numbers[3];
		four = numbers[4];
		five = numbers[5];
		six = numbers[6];
		seven = numbers[7];
		eight = numbers[8];

		numbers[0] = one;
		numbers[1] = two;
		numbers[2] = three;
		numbers[3] = four;
		numbers[4] = five;
		numbers[5] = six;
		numbers[6] = seven + zero;
		numbers[7] = eight;
		numbers[8] = zero;
		
		poblation += zero;
	}
	printf("%d\n", i);
	printf("poblation: %lld", poblation); // 8491536988 es too low
	return 0;
}