#include <stdio.h>
#include <string.h>

#define MAX 100
#define NMAX 20

int overlap(char *a, char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int max = 0;

    for (int k = 1; k <= lenA && k <= lenB; k++) {
        if (strncmp(a + lenA - k, b, k) == 0)
            max = k;
    }

    return max;
}

void mergeStrings(char *a, char *b, int ov) {
    int lenA = strlen(a);

    strcat(a, b + ov);
}

int main() {
    int n;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    char s[NMAX][MAX];

    printf("Enter the strings:\n");

    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);

    while (n > 1) {

        int maxOverlap = -1;
        int x = 0, y = 1;

        /* Find pair with maximum overlap */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                int ov = overlap(s[i], s[j]);

                if (ov > maxOverlap) {
                    maxOverlap = ov;
                    x = i;
                    y = j;
                }
            }
        }

        printf("\nMerging: %s + %s", s[x], s[y]);
        printf(" (overlap = %d)\n", maxOverlap);

        /* Merge s[y] into s[x] */
        mergeStrings(s[x], s[y], maxOverlap);

        /* Remove s[y] */
        for (int i = y; i < n - 1; i++)
            strcpy(s[i], s[i + 1]);

        n--;
    }

    printf("\nGreedy Superstring = %s\n", s[0]);

    return 0;
}