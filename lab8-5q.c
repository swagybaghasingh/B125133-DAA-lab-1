#include <stdio.h>

int main() {
    int n, a[100], dp[100];
    int i, j, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[i] = a[i];
    }

    for(i = 1; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(a[i] > a[j] &&
               dp[i] < dp[j] + a[i]) {
                dp[i] = dp[j] + a[i];
            }
        }
    }

    max = dp[0];

    for(i = 1; i < n; i++) {
        if(dp[i] > max)
            max = dp[i];
    }

    printf("Maximum sum = %d", max);

    return 0;
}