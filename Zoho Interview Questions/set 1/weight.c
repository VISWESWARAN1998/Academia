// SWAMI KARUPPASWAMI THUNNAI

/*
https://www.geeksforgeeks.org/zoho-interview-set-1-campus/
2. Given a set of numbers like <10, 36, 54,89,12> we want to find sum of weights based on the following conditions
1. 5 if a perfect square
2. 4 if multiple of 4 and divisible by 6
3. 3 if even number

And sort the numbers based on the weight and print it as follows

<10,its_weight>, <36,its weight> <89,its weight>
*/

#include<stdio.h>
#include<malloc.h>
#include<math.h>

struct perfect_square
{
	int size;
	int *array;
};

struct multiples_and_divisibles
{
	int size;
	int *array;
};

struct even
{
	int size;
	int *array;
};


int main()
{
	int total_numbers;
	// Get the total numbers want from the user
	printf("Total Numbers: ");
	scanf("%d", &total_numbers);
	// Allocate all the array with the necessary numbers
	// For perfect squares
	struct perfect_square squares;
	squares.array = (int*) malloc(total_numbers * sizeof(int));
	squares.size = 0;
	// For multiples and divisibles
	struct multiples_and_divisibles md;
	md.array = (int*) malloc(total_numbers * sizeof(int));
	md.size = 0;
	// For even numbers
	struct even even_array;
	even_array.array = (int*)malloc(total_numbers * sizeof(int));
	even_array.size = 0;
	for (int i = 0; i < total_numbers; i++)
	{
		int number;
		scanf("%d", &number);
		double square = sqrt(number);
		if ((square - floor(square)) == 0)
		{
			squares.size++;
			squares.array[squares.size - 1] = number;
		}
		else if ((number % 4 == 0) && (number % 6 == 0))
		{
			md.size++;
			md.array[md.size - 1] = number;
		}
		else if (number % 2 == 0)
		{
			even_array.size++;
			even_array.array[even_array.size - 1] = number;
		}
	}
	printf("\nPerfect Squares:\n");
	for (int i = 0; i < squares.size; i++)
	{
		printf("%d\n", squares.array[i]);
	}
	printf("\nMultiples of 4 and divisible by 6:\n");
	for (int i = 0; i < md.size; i++)
	{
		printf("%d\n", md.array[i]);
	}
	printf("\nEven numbers:\n");
	for (int i = 0; i < even_array.size; i++)
	{
		printf("%d\n", even_array.array[i]);
	}
	free(squares.array);
	free(md.array);
	free(even_array.array);
}
