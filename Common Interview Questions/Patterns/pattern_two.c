// SWAMI KARUPPASWAMI THUNNAI

#include<stdio.h>

int main()
{
	printf("Enter the maximum number: ");
	int max;
	scanf_s("%d", &max);
	getchar(); // Catch the new line
	for (int i = 1; i <= max; i++)
	{
		int temp = 1;
		while (temp <= (max-(i-1)))
		{
			printf("%d", temp);
			temp++;
		}
		printf("\n");
	}
	getchar();
}