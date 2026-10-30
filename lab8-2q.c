#include <stdio.h>

int main() {
    int n, V, i, j;
    int coins[100];
    int dp[1000] = {0};

    printf("Enter number of coins: ");
    scanf("%d", &n);

    printf("Enter coin denominations: ");
    for(i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("Enter target amount: ");
    scanf("%d", &V);

    dp[0] = 1;

    for(i = 0; i < n; i++) {
        for(j = coins[i]; j <= V; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    printf("Total number of ways = %d", dp[V]);

    return 0;
}