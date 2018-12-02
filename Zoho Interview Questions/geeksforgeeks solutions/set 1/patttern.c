// SWAMI KARUPPASWAMI THUNNAI

/*
https://www.geeksforgeeks.org/zoho-interview-set-1-campus/
Print the word with odd letters:
*/

#include<stdio.h>
#include<malloc.h>

struct Array
{
	char *container;
	int size;
};

int main()
{
	// Initailize the array
	struct Array array;
	array.container = (char*) malloc(0 * sizeof(char));
	array.size = 0;
	// Ask the user for the input
	printf("Enter your input: ");
	char ch;
	while ((ch = getchar()) != '\n')
	{
		array.size++;
		array.container = realloc(array.container, array.size * sizeof(char));
		array.container[array.size - 1] = ch;
	}
	if (array.size % 2 == 0)
	{
		printf("The characters you have entered is even!\n");
	}
	int row;
	int column;
	for (row = 0; row < array.size; row++)
	{
		for (column = 0; column < array.size; column++)
		{
			if (row == column) printf("%c", array.container[row]);
			else if (row + column == array.size - 1) printf("%c", array.container[column]);
			else printf(" ");
		}
		printf("\n");
	}
	free(array.container);
	array.size = 0;
	printf("\nFreed the dynamically allocated container");
	getchar();
}