#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int iq;
    int index;
} Elephant;

int compare(const void* a, const void* b) {
    Elephant* e1 = (Elephant*)a;
    Elephant* e2 = (Elephant*)b;

    // First sort by weight, if weights are the same, sort by decreasing IQ
    if (e1->weight != e2->weight)
        return e1->weight - e2->weight;
    else
        return e2->iq - e1->iq;
}

int main() {
    Elephant elephants[1000];
    int num_elephant = 0;

    int max_len = 0, max_index = -1;
    int dp[1000], prev[1000];

    printf("How many elephants? : ");
    scanf("%d", &num_elephant);

    for (int i = 0; i < num_elephant; i++) {
        scanf("%d %d", &elephants[i].weight, &elephants[i].iq);
        elephants[i].index = i + 1;  // Save the original index of each elephant
    }

    qsort(elephants, num_elephant, sizeof(Elephant), compare);

    for (int i = 0; i < num_elephant; i++) {
        dp[i] = 1;   // Initialize dp array with 1
        prev[i] = -1; // Initialize prev array with -1 (no previous elephant)
    }

    // Dynamic Programming to find the longest increasing subsequence
    for (int i = 1; i < num_elephant; i++) {
        for (int j = 0; j < i; j++) {
            // Check if the current elephant can come after elephant j
            if (elephants[i].weight > elephants[j].weight && elephants[i].iq < elephants[j].iq) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
    }

    // Find the index of the maximum value in dp[]
    for (int i = 0; i < num_elephant; i++) {
        if (dp[i] > max_len) {
            max_len = dp[i];
            max_index = i;
        }
    }

    // Dynamically allocate memory for the result array
    int* result = (int*)malloc(max_len * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Reconstruct the solution
    int count = 0;
    while (max_index != -1) {
        result[count++] = elephants[max_index].index;
        max_index = prev[max_index];
    }

    // Output the results in correct order
    printf("%d\n", max_len);
    for (int i = count - 1; i >= 0; i--) { // Print in reverse order
        printf("%d\n", result[i]);
    }

    // Free the dynamically allocated memory
    free(result);

    return 0;
}
