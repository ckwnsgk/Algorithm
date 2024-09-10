#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 30
#include <stdio.h>

int base_array[MAX_SIZE] = { 5,1,2,3,4 };
int new_array[MAX_SIZE] = { 0 , };


void cp_array(int main[] , int copy[])
{
	for (int i = 0; main[i] != 0; i++)
	{
		copy[i] = main[i];
	}
}

void func_flip(int flip , int index)
{
	int k = 0;
	for (int i = index - flip; i >= 0; i--)
	{
		new_array[k] = base_array[i];
		k++;
	}
}

void print_array(int* index)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (new_array[i] == 0)
		{
			*index = i;
			break;
		}
		printf("%d ", new_array[i]);
	}
	printf("\n");
}

int main()
{
	int index = 0;
	int flip = -1;
	cp_array(base_array,new_array);
	while (flip != 0)
	{
		print_array(&index);
		scanf_s("%d", &flip);

		if (flip == 0)
		{
			print_array(&index);
			break;
		}
		else
		{
			func_flip(flip, index);
			cp_array(new_array,base_array);
		}
	}

	return 0;
}