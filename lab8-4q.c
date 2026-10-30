#include <stdio.h>

int main() {
    int n, a[100], dp[100];
    int i, j, max = 1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[i] = 1;
    }

    for(i = 1; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(a[i] > a[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }

        if(dp[i] > max)
            max = dp[i];
    }

    printf("Length of LIS = %d", max);

    return 0;
}