#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_R 10001
#define MAX_S 101

unsigned long long dp[MAX_R][MAX_S];

void initialize_dp(int len_Resource)
{
    for (int i = 0; i < MAX_R; i++)
    {
        for (int j = 0; j < MAX_S; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i <= len_Resource; i++) {
        dp[i][0] = 1;
    }
}

int main() {
    int test = 0;
    printf("enter the number of test case : ");
    scanf("%d", &test); 

    for (int i = 0; i < test; i++)
    {

        char resource[MAX_R], sentence[MAX_S];
        scanf("%s %s", resource, sentence);

        int len_Resource = strlen(resource);
        int len_Sentence = strlen(sentence);

        initialize_dp(len_Resource);


        for (int i = 1; i <= len_Resource; i++) 
        {
            for (int j = 1; j <= len_Sentence; j++) 
            {
                if (resource[i - 1] == sentence[j - 1]) 
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else 
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        printf("%llu\n", dp[len_Resource][len_Sentence]);
    }

    return 0;
}
