#include <stdio.h>

int main()
{
    int n, i;
    int fib[100];

    printf("Enter the value of n: ");
    scanf("%d", &n);

    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("The %dth Fibonacci number is: %d\n", n, fib[n]);

    return 0;
}