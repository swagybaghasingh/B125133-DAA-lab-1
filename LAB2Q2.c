#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 2000

long long mergeCount = 0;
long long threeMergeCount = 0;


/* =========================================================
   NORMAL MERGE
   ========================================================= */
void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int size = right - left + 1;
    int temp[MAX_SIZE];

    while (i <= mid && j <= right)
    {
        mergeCount++;

        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < size; i++)
    {
        arr[left + i] = temp[i];
    }
}


/* =========================================================
   NORMAL MERGE SORT
   ========================================================= */
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


/* =========================================================
   THREE-WAY MERGE

   Merges three already sorted parts:
   Part 1 = left to mid1
   Part 2 = mid1+1 to mid2
   Part 3 = mid2+1 to right
   ========================================================= */
void threeWayMerge(int arr[], int left, int mid1,
                   int mid2, int right)
{
    int i = left;
    int j = mid1 + 1;
    int k = mid2 + 1;

    int index = 0;

    int size = right - left + 1;

    int temp[MAX_SIZE];

    while (i <= mid1 || j <= mid2 || k <= right)
    {
        /* All three parts have elements */
        if (i <= mid1 && j <= mid2 && k <= right)
        {
            threeMergeCount++;

            if (arr[i] <= arr[j])
            {
                threeMergeCount++;

                if (arr[i] <= arr[k])
                {
                    temp[index++] = arr[i++];
                }
                else
                {
                    temp[index++] = arr[k++];
                }
            }
            else
            {
                threeMergeCount++;

                if (arr[j] <= arr[k])
                {
                    temp[index++] = arr[j++];
                }
                else
                {
                    temp[index++] = arr[k++];
                }
            }
        }

        /* First and second parts have elements */
        else if (i <= mid1 && j <= mid2)
        {
            threeMergeCount++;

            if (arr[i] <= arr[j])
            {
                temp[index++] = arr[i++];
            }
            else
            {
                temp[index++] = arr[j++];
            }
        }

        /* First and third parts have elements */
        else if (i <= mid1 && k <= right)
        {
            threeMergeCount++;

            if (arr[i] <= arr[k])
            {
                temp[index++] = arr[i++];
            }
            else
            {
                temp[index++] = arr[k++];
            }
        }

        /* Second and third parts have elements */
        else if (j <= mid2 && k <= right)
        {
            threeMergeCount++;

            if (arr[j] <= arr[k])
            {
                temp[index++] = arr[j++];
            }
            else
            {
                temp[index++] = arr[k++];
            }
        }

        /* Only first part remains */
        else if (i <= mid1)
        {
            temp[index++] = arr[i++];
        }

        /* Only second part remains */
        else if (j <= mid2)
        {
            temp[index++] = arr[j++];
        }

        /* Only third part remains */
        else
        {
            temp[index++] = arr[k++];
        }
    }

    for (int x = 0; x < size; x++)
    {
        arr[left + x] = temp[x];
    }
}


/* =========================================================
   MODIFIED THREE-WAY MERGE SORT
   ========================================================= */
void threeWayMergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int n = right - left + 1;

        /*
           Divide array into approximately three parts
        */

        int third = n / 3;

        int mid1 = left + third - 1;

        int mid2 = left + 2 * third - 1;

        /*
           If n is not exactly divisible by 3,
           adjust the second middle point.
        */

        if (third == 0)
        {
            mid1 = left;
            mid2 = left;
        }

        if (mid2 >= right)
        {
            mid2 = right - 1;
        }

        threeWayMergeSort(arr, left, mid1);

        threeWayMergeSort(arr, mid1 + 1, mid2);

        threeWayMergeSort(arr, mid2 + 1, right);

        threeWayMerge(arr, left, mid1, mid2, right);
    }
}


/* =========================================================
   PRINT ARRAY
   ========================================================= */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}


/* =========================================================
   CREATE TEST ARRAY

   Descending order is used to create a difficult
   input for sorting.
   ========================================================= */
void createArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}


/* =========================================================
   GENERATE CSV DATA FOR GRAPH
   ========================================================= */
void generateGraphData()
{
    int sizes[] =
    {
        10, 20, 30, 40, 50,
        60, 70, 80, 90, 100,
        200, 300, 400, 500,
        600, 700, 800, 900,
        1000, 1200, 1400, 1600,
        1800, 2000
    };

    int numberOfSizes =
        sizeof(sizes) / sizeof(sizes[0]);

    FILE *fp;

    fp = fopen("Q2_growth.csv", "w");

    if (fp == NULL)
    {
        printf("\nError creating CSV file.\n");
        return;
    }

    /*
       CSV headings
    */
    fprintf(fp,
            "n,"
            "MergeSort_Comparisons,"
            "ThreeWayMergeSort_Comparisons,"
            "nlog2n,"
            "nlog3n\n");


    for (int x = 0; x < numberOfSizes; x++)
    {
        int n = sizes[x];

        int arr1[MAX_SIZE];
        int arr2[MAX_SIZE];

        createArray(arr1, n);
        createArray(arr2, n);

        /* Reset counters */
        mergeCount = 0;
        threeMergeCount = 0;

        /* Normal Merge Sort */
        mergeSort(arr1, 0, n - 1);

        /* Modified 3-Way Merge Sort */
        threeWayMergeSort(arr2, 0, n - 1);

        /*
           Theoretical growth values
        */
        double nlog2n = n * log2((double)n);

        double nlog3n =
            n * (log((double)n) / log(3.0));

        fprintf(fp,
                "%d,%lld,%lld,%.2f,%.2f\n",
                n,
                mergeCount,
                threeMergeCount,
                nlog2n,
                nlog3n);
    }

    fclose(fp);

    printf("\n========================================\n");
    printf("GRAPH DATA CREATED SUCCESSFULLY\n");
    printf("========================================\n");

    printf("File name: Q2_growth.csv\n");

    printf("\nOpen Q2_growth.csv in Microsoft Excel\n");
    printf("and create a Line Chart.\n");
}


/* =========================================================
   MAIN FUNCTION
   ========================================================= */
int main()
{
    int n;

    printf("========================================\n");
    printf("     Q2 - MERGE SORT vs 3-WAY MERGE SORT\n");
    printf("========================================\n");

    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE)
    {
        printf("\nInvalid value of n.\n");
        printf("Please enter n between 1 and %d.\n",
               MAX_SIZE);

        return 1;
    }


    int arr1[MAX_SIZE];
    int arr2[MAX_SIZE];


    /*
       Create same input for both algorithms
    */
    createArray(arr1, n);
    createArray(arr2, n);


    printf("\nOriginal Array:\n");

    if (n <= 50)
    {
        printArray(arr1, n);
    }
    else
    {
        printf("Array is too large to display.\n");
    }


    /* =====================================================
       NORMAL MERGE SORT
       ===================================================== */

    mergeCount = 0;

    mergeSort(arr1, 0, n - 1);

    printf("\nSorted using Merge Sort:\n");

    if (n <= 50)
    {
        printArray(arr1, n);
    }
    else
    {
        printf("Array sorted successfully.\n");
    }

    printf("\nComparison Count (Merge Sort): %lld\n",
           mergeCount);


    /* =====================================================
       THREE-WAY MERGE SORT
       ===================================================== */

    threeMergeCount = 0;

    threeWayMergeSort(arr2, 0, n - 1);

    printf("\nSorted using Modified 3-Way Merge Sort:\n");

    if (n <= 50)
    {
        printArray(arr2, n);
    }
    else
    {
        printf("Array sorted successfully.\n");
    }

    printf("\nComparison Count (3-Way Merge Sort): %lld\n",
           threeMergeCount);


    /* =====================================================
       COMPLEXITY
       ===================================================== */

    printf("\n========================================\n");
    printf("WORST CASE COMPLEXITY\n");
    printf("========================================\n");

    printf("\nMerge Sort:\n");
    printf("O(n log n)\n");

    printf("\nModified 3-Way Merge Sort:\n");
    printf("O(n log_3 n)\n");

    printf("\nSince log_3(n) = log(n)/log(3),\n");
    printf("Modified 3-Way Merge Sort is also:\n");
    printf("O(n log n)\n");


    /* =====================================================
       CREATE GRAPH DATA
       ===================================================== */

    generateGraphData();


    printf("\n========================================\n");
    printf("PROGRAM COMPLETED\n");
    printf("========================================\n");

    return 0;
}