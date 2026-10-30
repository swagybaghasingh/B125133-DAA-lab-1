
#include <stdio.h>

int main() {
    int n, i, j, a, b;
    int total, maxOverlap = 0;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    total = n * (n + 1) / 2;

    for (a = -n; a <= n; a++) {
        for (b = -n; b <= n; b++) {
            int overlap = 0;

            for (i = 0; i < n; i++) {
                for (j = 0; j < n - i; j++) {
                    int x = i - a;
                    int y = j - b;

                    if (x >= 0 && x < n &&
                        y >= 0 && y < n &&
                        x + y >= n - 1) {
                        overlap++;
                    }
                }
            }

            if (overlap > maxOverlap)
                maxOverlap = overlap;
        }
    }

    printf("Total coins: %d\n", total);
    printf("Maximum overlapping coins: %d\n", maxOverlap);
    printf("Minimum moves: %d\n", total - maxOverlap);

    return 0;
}
