#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1000
#include <stdio.h>

typedef struct
{
	int index;
	int time;
	int cent;
}JOB;

void input_array(JOB job_array[], int job)
{
	for (int i = 0; i < job; i++)
	{
		scanf_s("%d %d", &job_array[i].time, &job_array[i].cent);
		job_array[i].index = i + 1;
	}
}

void print_array(JOB job_array[], int job)
{
	for (int i = 0; i < job; i++)
	{
		printf("%d ", job_array[i].index);
	}
	printf("\n");
}
void align_array(JOB job_array[], int job)
{
	for (int k = 0; k < job - 1; k++)
	{
		for (int i = 0; i < job - k - 1; i++) 
		{
			double ratio1 = (double)job_array[i].cent / job_array[i].time;
			double ratio2 = (double)job_array[i + 1].cent / job_array[i + 1].time;

			if (ratio1 < ratio2)
			{

				JOB temp = job_array[i];
				job_array[i] = job_array[i + 1];
				job_array[i + 1] = temp;
			}
		}
	}
	printf("\n");
}


int main()
{
	JOB job_array[MAX_SIZE];
	int test = 0;
	scanf_s("%d",&test);
	printf("\n");

	while (test != 0)
	{
		int job = 0;
		scanf_s("%d",&job);

		input_array(job_array, job);
		align_array(job_array , job);
		print_array(job_array, job);

		test--;
	}
	return 0;
}