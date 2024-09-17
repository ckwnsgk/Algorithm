#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <stdio.h>


int calculate_deviation(float average, int people_money[], int people_num)
{
	int total_negative = 0;
	int total_positive = 0;
	for (int i = 0; i < people_num; i++)
	{
		if ((people_money[i] - average) < 0) //negative
		{
			people_money [i] = (people_money[i] - average) * -1;
			total_negative += people_money[i] - people_money[i] % 10;
		}
		else if((people_money[i] - average) >= 0) // positive
		{
			people_money[i] = (people_money[i] - average);
			total_positive += people_money[i] - people_money[i] % 10;
		}
	}
	
	return total_negative;
}

int calculate_average(int people_money[], int people_num)
{
	int sum = 0;
	for (int i = 0; i < people_num; i++)
	{
		sum += people_money[i];
	}
	float average = sum / people_num;
	return average;
}

int input(int* people_num , int people_money[])
{
	printf("enter the number of people : ");
	scanf_s("%d", people_num);

	if (*people_num <= 0 || *people_num > MAX_SIZE)
	{
		printf("error : range of people(1~100 !)");
		return -1;
	}
	for (int i = 0; i < *people_num; i++)
	{
		printf("person'%d : ", i + 1);
		scanf_s("%d", &people_money[i]);
	}
}

int main()
{
	int people_num = 0;
	int people_money[MAX_SIZE];
	input(&people_num , people_money);
	
	float average = calculate_average(people_money,people_num);

	printf("\n\nresult : %d", calculate_deviation(average, people_money, people_num));
	return 0;
}