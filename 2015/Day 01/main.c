#include <stdio.h>

int main(void)
{
	char c;
	int star1 = 0;
	int star2 = 0;
	int unique = 1;
	while(scanf("%c",&c) != EOF)
	{
		++star2;
		if(c == '(')
			star1++;
		else
			star1--;
		if(star1 == -1 && unique++ == 1)
			printf("STAR 2: %d\n", star2);
	}
	printf("STAR 1: %d\n", star1);
	return 0;
}