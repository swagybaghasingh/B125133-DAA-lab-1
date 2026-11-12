#include <stdio.h>

typedef struct {
    int weight;
    int left;
    int right;
} Node;

int main() {
    int n;

    printf("Enter number of weights: ");
    scanf("%d", &n);

    int w[n];

    printf("Enter weights:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    int totalCost = 0;

    printf("\nMerge operations:\n");

    while (n > 1) {

        int pos = 0;
        int minSum = w[0] + w[1];

        for (int i = 1; i < n - 1; i++) {
            int sum = w[i] + w[i + 1];

            if (sum < minSum) {
                minSum = sum;
                pos = i;
            }
        }

        printf("Merge %d and %d -> %d\n",
               w[pos], w[pos + 1], minSum);

        totalCost += minSum;

        w[pos] = minSum;

        for (int i = pos + 1; i < n - 1; i++)
            w[i] = w[i + 1];

        n--;
    }

    printf("\nTotal weighted path cost = %d\n",
           totalCost);

    return 0;
}