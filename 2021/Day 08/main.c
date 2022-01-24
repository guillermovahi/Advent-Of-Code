#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define input_file "prueba.txt"
#define input_lines 10

void file_to_array(char *array_input[input_lines][14]);
int get_digit(char *digit_encoded, int length);


int main(void)
{
	int star1 = 0, star2 = 0, n, n_line, digit;
	char *array_input[input_lines][14];
	
	file_to_array(array_input);
	
	for(int i = 0; i < input_lines; i++)
	{
		n_line = 0;
		for(int j = 10; j < 14; j++)
		{
			n = strlen(array_input[i][j]);
			if(n == 2)
				digit = 1;
			else if(n == 3)
				digit = 7;
			else if(n == 4)
				digit = 4;
			else if ( n == 7)
				digit = 8;
			
			if( n == 2 || n == 3 || n == 4 || n == 7)
				star1++; 
			else
				digit = get_digit(array_input[i][j], n);
			n_line = (n_line * 10) + digit;
		}
		printf("%d: %d\n", i, n_line);
		star2 += n_line;
	}
	printf("INPUT FOR STAR 1: %d\n", star1);
	printf("INPUT FOR STAR 2: %d\n", star2); // 1197548 too high

	/*
		strlen: numeros
		2: 1
		3: 7
		4: 4
		5: 2 3 5
		6: 6 9 0
		7: 8
	*/

	return 0;
}

int get_digit(char *digit_encoded, int length)
{
	int i, sum = 0;
	if (length == 5)
	{
		//recorro todo el numero codificado y sumo 1 para los comunes
		i = -1;
		while(++i < length)
		{
			if(digit_encoded[i] == 'e')
				return 5;
			if(digit_encoded[i] == 'g')
				return 2;
		}
		return 3;
	}
	else
	{
		i = 0;
		while(digit_encoded[i] != 'f')
			i++;
		if (i == length)
			return 0;
		
		i = -1;
		while(++i < length)
		{
			if(digit_encoded[i] == 'a')
				return 9;
			if(digit_encoded[i] == 'g')
				return 6;
		}
	}
	return -1;
	/*
		 dddd
		e    a
		e    a
		 ffff
		g    b
		g    b
		 cccc
	*/
}

void file_to_array(char *array_input[input_lines][14])
{
	FILE *my_input = fopen(input_file, "r");
	char signal1[8], signal2[8], signal3[8], signal4[8], signal5[8], signal6[8], signal7[8], signal8[8], signal9[8], signal10[8]; 
	char output1[8], output2[8], output3[8], output4[8];

	for(int i = 0; i < input_lines; i++)
	{
		fscanf(my_input, "%s %s %s %s %s %s %s %s %s %s | %s %s %s %s",
				&signal1, &signal2, &signal3, &signal4, &signal5, 
				&signal6, &signal7, &signal8, &signal9, &signal10, 
				output1, &output2, &output3, &output4);

		array_input[i][0] = strdup(signal1);
		array_input[i][1] = strdup(signal2);
		array_input[i][2] = strdup(signal3);
		array_input[i][3] = strdup(signal4);
		array_input[i][4] = strdup(signal5);
		array_input[i][5] = strdup(signal6);
		array_input[i][6] = strdup(signal7);
		array_input[i][7] = strdup(signal8);
		array_input[i][8] = strdup(signal9);
		array_input[i][9] = strdup(signal10);
		array_input[i][10] = strdup(output1);
		array_input[i][11] = strdup(output2);
		array_input[i][12] = strdup(output3);
		array_input[i][13] = strdup(output4);
	}
	fclose(my_input);
}

