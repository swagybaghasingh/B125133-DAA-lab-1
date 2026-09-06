#include <stdio.h>
#include <math.h>

#define MAX 10

void display(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);

        printf("\n");
    }
}

void addition(int a[MAX][MAX], int b[MAX][MAX],
              int c[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
    }
}

void multiplication(int a[MAX][MAX], int b[MAX][MAX],
                    int c[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;

            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

int isZero(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
                return 0;
        }
    }

    return 1;
}

int isSymmetric(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][j] != a[j][i])
                return 0;
        }
    }

    return 1;
}

double determinant(double a[MAX][MAX], int n)
{
    double det = 1;

    for (int i = 0; i < n; i++)
    {
        int pivot = i;

        for (int j = i + 1; j < n; j++)
        {
            if (fabs(a[j][i]) > fabs(a[pivot][i]))
                pivot = j;
        }

        if (fabs(a[pivot][i]) < 1e-9)
            return 0;

        if (pivot != i)
        {
            for (int j = 0; j < n; j++)
            {
                double temp = a[i][j];
                a[i][j] = a[pivot][j];
                a[pivot][j] = temp;
            }

            det = -det;
        }

        det *= a[i][i];

        for (int j = i + 1; j < n; j++)
        {
            double factor = a[j][i] / a[i][i];

            for (int k = i; k < n; k++)
                a[j][k] -= factor * a[i][k];
        }
    }

    return det;
}

void transpose(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}

/* Power iteration finds the dominant eigenvalue
   and corresponding eigenvector. */

void eigen(int a[MAX][MAX], int n)
{
    double x[MAX], y[MAX];
    double lambda = 0;

    for (int i = 0; i < n; i++)
        x[i] = 1;

    for (int iteration = 0; iteration < 1000; iteration++)
    {
        double maxValue = 0;

        for (int i = 0; i < n; i++)
        {
            y[i] = 0;

            for (int j = 0; j < n; j++)
                y[i] += a[i][j] * x[j];

            if (fabs(y[i]) > maxValue)
                maxValue = fabs(y[i]);
        }

        for (int i = 0; i < n; i++)
            x[i] = y[i] / maxValue;

        lambda = maxValue;
    }

    printf("Dominant Eigenvalue = %.4f\n", lambda);
    printf("Corresponding Eigenvector:\n");

    for (int i = 0; i < n; i++)
        printf("%.4f\n", x[i]);
}

int main()
{
    int n;
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    double d[MAX][MAX];

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter Matrix A:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter Matrix B:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &b[i][j]);

    addition(a, b, c, n);

    printf("\nMatrix Addition:\n");
    display(c, n);

    multiplication(a, b, c, n);

    printf("\nMatrix Multiplication:\n");
    display(c, n);

    if (isZero(a, n))
        printf("\nA is a zero matrix.\n");
    else
        printf("\nA is not a zero matrix.\n");

    if (isSymmetric(a, n))
        printf("A is symmetric.\n");
    else
        printf("A is not symmetric.\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = a[i][j];

    printf("\nDeterminant = %.2f\n", determinant(d, n));

    transpose(a, n);

    printf("\nTranspose of A:\n");
    display(a, n);

    eigen(b, n);

    return 0;
}