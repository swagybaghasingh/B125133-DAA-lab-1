#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void collatz(unsigned long long n) {
    unsigned long long *arr;
    int count = 0, capacity = 10, i;

    arr = malloc(capacity * sizeof(unsigned long long));

    if(arr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Collatz sequence: ");

    while(1) {
        if(count == capacity) {
            capacity *= 2;

            unsigned long long *temp =
                realloc(arr, capacity * sizeof(unsigned long long));

            if(temp == NULL) {
                printf("\nMemory allocation failed");
                free(arr);
                return;
            }

            arr = temp;
        }

        arr[count++] = n;

        if(n == 1)
            break;

        if(n % 2 == 0)
            n = n / 2;
        else {
            if(n > (ULLONG_MAX - 1) / 3) {
                printf("\nInteger overflow detected");
                free(arr);
                return;
            }

            n = 3 * n + 1;
        }
    }

    for(i = 0; i < count; i++)
        printf("%llu ", arr[i]);

    printf("\nTotal steps = %d\n", count - 1);

    free(arr);
}

int main() {
    unsigned long long n, a, b, i;

    printf("Enter starting number: ");
    scanf("%llu", &n);

    if(n == 0) {
        printf("Enter a positive number");
        return 0;
    }

    collatz(n);

    printf("\nEnter interval (a b): ");
    scanf("%llu %llu", &a, &b);

    if(a == 0 || a > b) {
        printf("Invalid interval");
        return 0;
    }

    printf("\nCollatz steps in interval:\n");

    for(i = a; ; i++) {
        unsigned long long x = i;
        int steps = 0;

        while(x != 1) {
            if(x % 2 == 0)
                x = x / 2;
            else {
                if(x > (ULLONG_MAX - 1) / 3) {
                    printf("%llu: Overflow detected\n", i);
                    break;
                }

                x = 3 * x + 1;
            }

            steps++;
        }

        if(x == 1)
            printf("%llu: %d steps\n", i, steps);

        if(i == b)
            break;
    }

    return 0;
}