#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count(int apple , int box1_num , int box1_cost , int box2_num , int box2_cost)
{
	int best_cost = 10000;
	int best_m1 = -1;
	int best_m2 = -1;
	int m1 = 0 , m2 = 0;
	for (m1 = 0; m1*box1_num <= apple; m1++)
	{
		int remain_apple = apple - m1 * box1_num;
		if (remain_apple % box2_num == 0)
		{
			m2 = remain_apple / box2_num;

			if (best_cost > (m1 * box1_cost) + (m2 * box2_cost))
			{
				best_cost = (m1 * box1_cost) + (m2 * box2_cost);
				best_m1 = m1;
				best_m2 = m2;
			}
		}
	}
	if (best_cost == 10000)
	{
		printf("Faild !!\n");
	}
	else
	{
		printf("best cost is : %d\n", best_cost);
		printf("best box1 num : %d\n", best_m1);
		printf("best box2 num : %d\n", best_m2);
	}

}

int main()
{
	int apple_num = 0;
	int box1_num = 0;
	int box2_num = 0;
	int box1_cost = 0;
	int box2_cost = 0;
	int user = 1;
	do
	{
		printf("enter the number of apple : ");
		scanf_s("%d", &apple_num);
		scanf_s("%d %d", &box1_cost, &box1_num);
		scanf_s("%d %d", &box2_cost, &box2_num);

		count(apple_num, box1_num, box1_cost, box2_num, box2_cost);

		printf("want you stop? enter the '0' :");
		scanf_s("%d", &user);
	} while (user != 0);
	
	printf("\n--------------------system exit--------------------\n");
	return 0;
}