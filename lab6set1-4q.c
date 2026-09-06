#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j, k, l;
    int arr[50];
    int dp[50][50];
    int cost;

    printf("Enter N: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (l = 2; l < n; l++)
    {
        for (i = 1; i < n - l + 1; i++)
        {
            j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (k = i; k < j; k++)
            {
                cost = dp[i][k]
                     + dp[k + 1][j]
                     + arr[i - 1] * arr[k] * arr[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications = %d\n",
           dp[1][n - 1]);

    return 0;
}