#include <stdio.h>

int main() {
    int n, p[100], dp[100], cut[100];
    int i, j, max;

    printf("Enter rod length: ");
    scanf("%d", &n);

    printf("Enter prices: ");
    for(i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    dp[0] = 0;

    for(i = 1; i <= n; i++) {
        max = -1;

        for(j = 1; j <= i; j++) {
            if(p[j] + dp[i-j] > max) {
                max = p[j] + dp[i-j];
                cut[i] = j;
            }
        }

        dp[i] = max;
    }

    printf("Maximum revenue = %d\n", dp[n]);

    printf("Rod pieces: ");

    while(n > 0) {
        printf("%d ", cut[n]);
        n = n - cut[n];
    }

    return 0;
}