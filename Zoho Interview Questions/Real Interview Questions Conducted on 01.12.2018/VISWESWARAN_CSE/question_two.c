// SWAMI KARUPPASWAMI THUNNAI

#include<stdio.h>
#include<malloc.h>

// This method will check whether the string is a plaindrome or not
int is_palindrome(char* string, int size)
{
	int palindrome = 1;
	char *reversed = (char*)malloc(size * sizeof(char));
	// Add the values in reversed order
	int reversed_index = 0;
	for (int i = size-1; i >= 0; i--)
	{
		reversed_index++;
		reversed[reversed_index-1] = string[i];
	}
	// Check if both the strings are equal
	for (int i = 0; i < size; i++)
	{
		if (string[i] != reversed[i])
		{
			palindrome = 0;
			break;
		}
	}
	free(reversed);
	return palindrome;
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char *string, int left, int right)
{
	if (left == right)
	{
		if (is_palindrome(string, right+1) == 1) 
		{
			for (int i = 0; i <= right; i++) printf("%c", string[i]);
			printf("\n");	
		}
	}
	else
	{
		for (int i = left; i <= right; i++)
		{
			swap((string + left), (string + i));
			permute(string, left + 1, right);
			swap((string + left), (string + i));
		}
	}
}

unsigned int factorial(unsigned int input_size)
{
	unsigned int n = 1;
	for (int i = input_size; i >= 1; i++)
	{
		n = n * i;
	}
	return n;
}

int main()
{
	printf("Enter your string: ");
	char *input_string = (char*)malloc(0 * sizeof(char));
	unsigned int input_size = 0;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (ch >= 65 && ch <= 90) ch += 32; // Convert the character to lower case
		input_size++;
		input_string = realloc(input_string, input_size * sizeof(char));
		input_string[input_size - 1] = ch;
	}
	permute(input_string, 0, input_size - 1);
	free(input_string);
	printf("\nProcesss completed. Freed the memory! Press ENTER to exit!");
	getchar();
}