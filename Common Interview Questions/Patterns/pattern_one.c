// SWAMI KARUPPASWAMI THUNNAI

#include<stdio.h>

int main()
{
	printf("count: ");
	int count;
	scanf_s("%d", &count);
	getchar(); // catch the new line
	for (int i = 1; i <= count; i++)
	{
		for (int j = i; j >= 1; j--) printf("%d", j);
		printf("\n");
	}
	getchar();
}