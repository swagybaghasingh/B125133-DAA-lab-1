#include <stdio.h>
#include <string.h>

int main() {
    char X[100], Y[100], lcs[100];
    int dp[100][100];
    int m, n, i, j, k;

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    m = strlen(X);
    n = strlen(Y);

    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = dp[i-1][j] > dp[i][j-1]
                         ? dp[i-1][j] : dp[i][j-1];
        }
    }

    i = m;
    j = n;
    k = dp[m][n];

    lcs[k] = '\0';

    while(i > 0 && j > 0) {
        if(X[i-1] == Y[j-1]) {
            lcs[--k] = X[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    printf("LCS Length = %d\n", dp[m][n]);
    printf("LCS = %s", lcs);

    return 0;
}