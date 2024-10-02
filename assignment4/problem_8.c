#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input_matrix[10][100];
int dp[10][100];
int path[10][100];

int min(int a , int b , int c)
{
    if (a <= b && a <= c)
    {
        return a;
    }
    else if (b <= c && b <= a)
    {
        return b;
    }
    else
    {
        return c;
    }
}



void dp_setting(row, col)
{

    for (int j = 1; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            int up = dp[(i - 1 + row) % row][j - 1];
            int shift = dp[i][j - 1];
            int down = dp[(i + 1) % row][j - 1];

            dp[i][j] = input_matrix[i][j] + min(up, shift, down);
           
            if (dp[i][j] == input_matrix[i][j] + up)
            {
                path[i][j] = (i - 1 + row) % row;
            }
            else if (dp[i][j] == input_matrix[i][j] + shift)
            {
                path[i][j] = i;
            }
            else if (dp[i][j] == input_matrix[i][j] + down)
            {
                path[i][j] = (i + 1) % row;
            }
        }
    }
}

void dp_initialize(int row , int col)
{
    for (int i = 0; i < row; i++)
    {
        dp[i][0] = input_matrix[i][0];
    }
}

void find_min_path(int row, int col , int find_row)
{
    int result_path[100] = {-1,};
    int current_row = find_row;

    for (int u = col-1; u >= 0; u--)
    {
        result_path[u] = input_matrix[current_row][u];
        current_row = path[current_row][u];
    }

    for (int k = 0; k < col; k++)
    {
        printf("%d ",result_path[k]);
    }
}

void find_min_cost(int row, int col)
{
    int find_row = 0;
    int min = 10000;
    for (int p = 0; p < row; p++)
    {
        if (min > dp[p][col - 1])
        {
            find_row = p;
            min = dp[p][col - 1];
        }
    }
    find_min_path(row, col,find_row);
    printf("\nmin_cost : %d",min);

    printf("\n");
}

void solve_dp(int row, int col)
{
    dp_initialize(row,col);
    dp_setting(row,col);
    find_min_cost(row, col);
}

int main() 
{
    int row = 0;
    int col = 0;
    while (scanf_s("%d %d", &row, &col) != EOF)
    {

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++) 
            {
                scanf_s("%d", &input_matrix[i][j]);
            }
        }

        solve_dp(row, col);
    }

    return 0;
}