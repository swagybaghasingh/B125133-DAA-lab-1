
#include <stdio.h>

int dp[20], split[20];
int moves = 0;

void toh3(int n, char s, char d, char a) {
    if (n == 0) return;

    toh3(n - 1, s, a, d);

    printf("Move disk %d from %c to %c\n", n, s, d);
    moves++;

    toh3(n - 1, a, d, s);
}

void toh4(int n, char s, char d, char a, char b) {
    if (n == 0) return;

    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", s, d);
        moves++;
        return;
    }

    int k = split[n];

    toh4(k, s, a, d, b);
    toh3(n - k, s, d, b);
    toh4(k, a, d, s, b);
}

int main() {
    int n, i, k;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    dp[0] = 0;

    for (i = 1; i <= n; i++) {
        dp[i] = 999999;

        for (k = 0; k < i; k++) {
            int temp = 2 * dp[k] +
                       (1 << (i - k)) - 1;

            if (temp < dp[i]) {
                dp[i] = temp;
                split[i] = k;
            }
        }
    }

    printf("\nMinimum moves: %d\n\n", dp[n]);

    toh4(n, 'A', 'D', 'B', 'C');

    printf("\nTotal moves performed: %d\n", moves);

    return 0;
}
