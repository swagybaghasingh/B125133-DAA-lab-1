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

    printf("Enter number of sticks: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter stick lengths:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int totalCost = 0;

    while (n > 1) {
        sort(a, n);

        int cost = a[0] + a[1];

        totalCost += cost;

        a[0] = cost;

        for (int i = 1; i < n - 1; i++)
            a[i] = a[i + 1];

        n--;
    }

    printf("Minimum total cost = %d\n", totalCost);

    return 0;
}