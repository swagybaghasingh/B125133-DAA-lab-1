#include <stdio.h>

#define INF 99999

int main() {
    int n, V, i, j;
    int coin[100], dp[1000];

    printf("Enter number of coins: ");
    scanf("%d", &n);

    printf("Enter coin denominations: ");
    for(i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    printf("Enter target amount: ");
    scanf("%d", &V);

    for(i = 0; i <= V; i++)
        dp[i] = INF;

    dp[0] = 0;

    for(i = 1; i <= V; i++) {
        for(j = 0; j < n; j++) {
            if(coin[j] <= i &&
               dp[i - coin[j]] != INF) {
                if(dp[i - coin[j]] + 1 < dp[i])
                    dp[i] = dp[i - coin[j]] + 1;
            }
        }
    }

    if(dp[V] == INF)
        printf("Not possible");
    else
        printf("Minimum coins = %d", dp[V]);

    return 0;
}