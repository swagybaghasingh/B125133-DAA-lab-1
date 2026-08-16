#include <stdio.h>

#define MAX 64

void addMatrix(int A[][MAX], int B[][MAX],
               int C[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(int A[][MAX], int B[][MAX],
                    int C[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void specialMultiply(int A[][MAX], int B[][MAX],
                     int C[][MAX], int n)
{
    /* Base case: single integer */
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    /*
       A = [ A1  A2 ]
           [ A2  A1 ]

       B = [ B1  B2 ]
           [ B2  B1 ]
    */

    int A1[MAX][MAX], A2[MAX][MAX];
    int B1[MAX][MAX], B2[MAX][MAX];

    int Aplus[MAX][MAX], Aminus[MAX][MAX];
    int Bplus[MAX][MAX], Bminus[MAX][MAX];

    int P[MAX][MAX], Q[MAX][MAX];

    int C1[MAX][MAX], C2[MAX][MAX];

    /* Divide matrices into blocks */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    /*
       P = (A1 + A2)(B1 + B2)
       Q = (A1 - A2)(B1 - B2)
    */

    addMatrix(A1, A2, Aplus, k);
    addMatrix(B1, B2, Bplus, k);

    subtractMatrix(A1, A2, Aminus, k);
    subtractMatrix(B1, B2, Bminus, k);

    /* Two recursive multiplications */

    specialMultiply(Aplus, Bplus, P, k);
    specialMultiply(Aminus, Bminus, Q, k);

    /*
       C1 = (P + Q) / 2
       C2 = (P - Q) / 2

       Result:
       
       C = [ C1  C2 ]
           [ C2  C1 ]
    */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C1[i][j] = (P[i][j] + Q[i][j]) / 2;
            C2[i][j] = (P[i][j] - Q[i][j]) / 2;
        }
    }

    /* Construct final matrix */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C1[i][j];
            C[i][j + k] = C2[i][j];

            C[i + k][j] = C2[i][j];
            C[i + k][j + k] = C1[i][j];
        }
    }
}

int main()
{
    int n;

    printf("Enter matrix size: ");
    scanf("%d", &n);

    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];

    printf("Enter Matrix A:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter Matrix B:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    specialMultiply(A, B, C, n);

    printf("\nResult Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }

        printf("\n");
    }

    return 0;
}