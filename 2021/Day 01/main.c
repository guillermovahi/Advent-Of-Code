#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *arr = malloc(2000 * sizeof(int));
    int i = 0, j = 0, k = 1, l = 2, num, star1 = 0, star2 = 0;
	
	while(scanf("%d", &num) && i < 2000)
		arr[i++] = num;
	
	//STAR 1
	while(k < i)
	{
		if(arr[k++] > arr[j++])
			star1++;
	}
	//STAR 2
	j = 0;
	k = 1;
	while(l < i)
	{
		if((arr[j] + arr[k] + arr[l]) < (arr[++j] + arr[++k] + arr[++l]))
			star2++;
	}

	printf("INPUT FOR STAR 1: %d\n", star1);
	printf("INPUT FOR STAR 2: %d\n", star2);
	return 0;
}