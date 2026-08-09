#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_K 64
#define MAX_N 100

/* -------------------------------------------------
   Merge two sorted arrays
   ------------------------------------------------- */
void mergeArrays(int a[], int n1, int b[], int n2, int result[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            result[k++] = a[i++];
        }
        else
        {
            result[k++] = b[j++];
        }
    }

    while (i < n1)
    {
        result[k++] = a[i++];
    }

    while (j < n2)
    {
        result[k++] = b[j++];
    }
}


/* -------------------------------------------------
   METHOD 1
   Merge first two arrays, then result with third,
   then fourth, and so on.
   ------------------------------------------------- */
void method1(int arr[][MAX_N], int k, int n, int result[])
{
    int total = n;
    int temp[MAX_K * MAX_N];

    /* Copy first array */
    for (int i = 0; i < n; i++)
    {
        result[i] = arr[0][i];
    }

    /* Merge one array at a time */
    for (int i = 1; i < k; i++)
    {
        mergeArrays(result, total,
                    arr[i], n,
                    temp);

        total = total + n;

        for (int j = 0; j < total; j++)
        {
            result[j] = temp[j];
        }
    }
}


/* -------------------------------------------------
   METHOD 2
   Merge arrays in pairs.
   Repeat until only one sorted array remains.
   ------------------------------------------------- */
void method2(int arr[][MAX_N], int k, int n, int result[])
{
    int current[MAX_K][MAX_K * MAX_N];
    int next[MAX_K][MAX_K * MAX_N];

    int sizes[MAX_K];
    int nextSizes[MAX_K];

    /* Copy original arrays */
    for (int i = 0; i < k; i++)
    {
        sizes[i] = n;

        for (int j = 0; j < n; j++)
        {
            current[i][j] = arr[i][j];
        }
    }

    int count = k;

    /* Keep merging pairs */
    while (count > 1)
    {
        int newCount = 0;

        for (int i = 0; i < count; i += 2)
        {
            if (i + 1 < count)
            {
                mergeArrays(
                    current[i],
                    sizes[i],
                    current[i + 1],
                    sizes[i + 1],
                    next[newCount]
                );

                nextSizes[newCount] =
                    sizes[i] + sizes[i + 1];

                newCount++;
            }
            else
            {
                /* If odd number of arrays,
                   copy the last one */
                for (int j = 0; j < sizes[i]; j++)
                {
                    next[newCount][j] =
                        current[i][j];
                }

                nextSizes[newCount] = sizes[i];
                newCount++;
            }
        }

        /* Copy next level to current */
        for (int i = 0; i < newCount; i++)
        {
            sizes[i] = nextSizes[i];

            for (int j = 0; j < sizes[i]; j++)
            {
                current[i][j] = next[i][j];
            }
        }

        count = newCount;
    }

    /* Copy final result */
    for (int i = 0; i < sizes[0]; i++)
    {
        result[i] = current[0][i];
    }
}


/* -------------------------------------------------
   Display an array
   ------------------------------------------------- */
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}


/* -------------------------------------------------
   Main
   ------------------------------------------------- */
int main()
{
    int k, n;

    printf("Enter number of sorted arrays (k): ");
    scanf("%d", &k);

    printf("Enter number of elements in each array (n): ");
    scanf("%d", &n);

    if (k <= 0 || k > MAX_K ||
        n <= 0 || n > MAX_N)
    {
        printf("Invalid input.\n");
        return 1;
    }

    int arr[MAX_K][MAX_N];

    /*
       Generate sorted arrays.

       Each array contains values in increasing order.
    */
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = j + 1 + i * 100;
        }
    }

    printf("\nInput Sorted Arrays:\n");

    for (int i = 0; i < k; i++)
    {
        printf("Array %d: ", i + 1);
        display(arr[i], n);
    }


    /* ---------------- METHOD 1 ---------------- */

    int result1[MAX_K * MAX_N];

    clock_t start1 = clock();

    method1(arr, k, n, result1);

    clock_t end1 = clock();

    double time1 =
        (double)(end1 - start1) / CLOCKS_PER_SEC;


    /* ---------------- METHOD 2 ---------------- */

    int result2[MAX_K * MAX_N];

    clock_t start2 = clock();

    method2(arr, k, n, result2);

    clock_t end2 = clock();

    double time2 =
        (double)(end2 - start2) / CLOCKS_PER_SEC;


    /* ---------------- RESULTS ---------------- */

    printf("\n====================================\n");
    printf("METHOD 1 RESULT\n");
    printf("====================================\n");

    printf("Merged Array:\n");
    display(result1, k * n);

    printf("Time taken = %lf seconds\n", time1);


    printf("\n====================================\n");
    printf("METHOD 2 RESULT\n");
    printf("====================================\n");

    printf("Merged Array:\n");
    display(result2, k * n);

    printf("Time taken = %lf seconds\n", time2);


    /* ---------------- COMPLEXITY ---------------- */

    printf("\n====================================\n");
    printf("TIME COMPLEXITY\n");
    printf("====================================\n");

    printf("Method 1 : O(n * k^2)\n");
    printf("Method 2 : O(n * k * log2(k))\n");


    /* ---------------- VERIFICATION ---------------- */

    int correct = 1;

    for (int i = 0; i < k * n; i++)
    {
        if (result1[i] != result2[i])
        {
            correct = 0;
            break;
        }
    }

    if (correct)
    {
        printf("\nBoth methods produced the same sorted array.\n");
    }
    else
    {
        printf("\nResults are different.\n");
    }

    return 0;
}