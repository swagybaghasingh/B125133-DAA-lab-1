
#include <stdio.h>

int main() {
    int e, f, i, j, x;
    int dp[20][101];

    printf("Enter number of eggs: ");
    scanf("%d", &e);

    printf("Enter number of floors: ");
    scanf("%d", &f);

    for (i = 1; i <= e; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (j = 1; j <= f; j++)
        dp[1][j] = j;

    for (i = 2; i <= e; i++) {
        for (j = 2; j <= f; j++) {
            dp[i][j] = 9999;

            for (x = 1; x <= j; x++) {
                int res = 1 +
                    (dp[i-1][x-1] > dp[i][j-x]
                    ? dp[i-1][x-1]
                    : dp[i][j-x]);

                if (res < dp[i][j])
                    dp[i][j] = res;
            }
        }
    }

    printf("Minimum number of drops: %d\n", dp[e][f]);

    return 0;
}
