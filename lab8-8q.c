#include <stdio.h>

int main() {
    int n, i, j, l, r;
    float p[20], q[20];
    float e[20][20], w[20][20];
    int root[20][20];

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter successful probabilities: ");
    for(i = 1; i <= n; i++)
        scanf("%f", &p[i]);

    printf("Enter unsuccessful probabilities: ");
    for(i = 0; i <= n; i++)
        scanf("%f", &q[i]);

    for(i = 1; i <= n + 1; i++) {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }

    for(l = 1; l <= n; l++) {
        for(i = 1; i <= n-l+1; i++) {
            j = i+l-1;

            e[i][j] = 999999;

            w[i][j] = w[i][j-1]
                    + p[j] + q[j];

            for(r = i; r <= j; r++) {
                float cost = e[i][r-1]
                           + e[r+1][j]
                           + w[i][j];

                if(cost < e[i][j]) {
                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("Minimum expected search cost = %.3f",
           e[1][n]);

    return 0;
}