#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int n, W, i, w;
    int weight[50], profit[50];
    int dp[50][100];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter the weights:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    printf("Enter the profits:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    for (w = 0; w <= W; w++)
        dp[0][w] = 0;

    for (i = 1; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum profit = %d\n", dp[n][W]);

    return 0;
}