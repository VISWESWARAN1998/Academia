// SWAMI KARUPPASWAMI THUNNAI

#include<stdio.h>
#include<malloc.h>

struct container
{
	int *array;
	int *is_integer;
	int size;
};

void check_and_display(struct container *checker, int value, int is_integer)
{
	int is_value_present = 0;
	for (int i = 0; i<checker->size; i++)
	{
		if (checker->is_integer == 1 && is_integer == 1)
		{
			int array_value = checker->array[i];
			if (array_value == value)
			{
				is_value_present = 1;
			}
		}
		else
		{
			char array_value = checker->array[i];
			char value_to_be_checked = value;
			if (array_value == value_to_be_checked) is_value_present = 1;
		}
	}
	if (is_value_present == 1)
	{
		value++;
		check_and_display(checker, value, is_integer);
	}
	else
	{
		if (is_integer == 1) printf("%d", value);
		else printf("%c", value);
		checker->array[checker->size] = value;
		checker->is_integer[checker->size] = value;
		checker->size++;
	}
}

void replace(char* string, int size)
{
	struct container checker;
	checker.size = 0;
	// Two arrays one to hold the value(which acts like a container) and the other to check whether it is integer or string
	checker.array = (int*)malloc(size * sizeof(int));
	checker.is_integer = (int*)malloc(size * sizeof(int));
	for (int i = 0; i<size; i++)
	{
		char current_char = string[i];
		if (isdigit(current_char)) check_and_display(&checker, current_char - '0', 1);
		else check_and_display(&checker, current_char, 0);
	}

}


int main()
{
	printf("Enter your string: ");
	char *string = (char*)malloc(0 * sizeof(char));
	unsigned int size = 0;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		size++;
		string = realloc(string, size * sizeof(char));
		string[size - 1] = ch;
	}
	replace(string, size);
	getchar();
}