#include <stdio.h>

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter positive integers:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    /*
       Make all odd values even by multiplying by 2.
    */
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0)
            a[i] *= 2;
    }

    int minDeviation = 1000000000;

    while (1) {
        sort(a, n);

        int deviation = a[n - 1] - a[0];

        if (deviation < minDeviation)
            minDeviation = deviation;

        /* Maximum is even, so divide it */
        if (a[n - 1] % 2 != 0)
            break;

        a[n - 1] /= 2;
    }

    printf("Minimum deviation = %d\n", minDeviation);

    return 0;
}