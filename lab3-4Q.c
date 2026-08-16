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

void strassen(int A[][MAX], int B[][MAX],
              int C[][MAX], int n)
{
    /* Base case */
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A11[MAX][MAX], A12[MAX][MAX];
    int A21[MAX][MAX], A22[MAX][MAX];

    int B11[MAX][MAX], B12[MAX][MAX];
    int B21[MAX][MAX], B22[MAX][MAX];

    int M1[MAX][MAX], M2[MAX][MAX];
    int M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX];
    int M7[MAX][MAX];

    int T1[MAX][MAX], T2[MAX][MAX];

    /* Divide A and B into four sub-matrices */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    /* M1 = (A11 + A22)(B11 + B22) */

    addMatrix(A11, A22, T1, k);
    addMatrix(B11, B22, T2, k);
    strassen(T1, T2, M1, k);

    /* M2 = (A21 + A22)B11 */

    addMatrix(A21, A22, T1, k);
    strassen(T1, B11, M2, k);

    /* M3 = A11(B12 - B22) */

    subtractMatrix(B12, B22, T1, k);
    strassen(A11, T1, M3, k);

    /* M4 = A22(B21 - B11) */

    subtractMatrix(B21, B11, T1, k);
    strassen(A22, T1, M4, k);

    /* M5 = (A11 + A12)B22 */

    addMatrix(A11, A12, T1, k);
    strassen(T1, B22, M5, k);

    /* M6 = (A21 - A11)(B11 + B12) */

    subtractMatrix(A21, A11, T1, k);
    addMatrix(B11, B12, T2, k);
    strassen(T1, T2, M6, k);

    /* M7 = (A12 - A22)(B21 + B22) */

    subtractMatrix(A12, A22, T1, k);
    addMatrix(B21, B22, T2, k);
    strassen(T1, T2, M7, k);

    /* Calculate result matrix */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            /* C11 = M1 + M4 - M5 + M7 */
            C[i][j] = M1[i][j] + M4[i][j]
                    - M5[i][j] + M7[i][j];

            /* C12 = M3 + M5 */
            C[i][j + k] = M3[i][j] + M5[i][j];

            /* C21 = M2 + M4 */
            C[i + k][j] = M2[i][j] + M4[i][j];

            /* C22 = M1 - M2 + M3 + M6 */
            C[i + k][j + k] = M1[i][j] - M2[i][j]
                            + M3[i][j] + M6[i][j];
        }
    }
}

int main()
{
    int n;

    int A[MAX][MAX];
    int B[MAX][MAX];
    int C[MAX][MAX];

    printf("Enter matrix size: ");
    scanf("%d", &n);

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

    strassen(A, B, C, n);

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