#include <stdio.h>
#include <math.h>

void findMax(int a[], int n)
{
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    printf("Maximum = %d\n", max);
}

void findLargest(int a[], int n)
{
    int first = a[0], second = -999999;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > first)
        {
            second = first;
            first = a[i];
        }
        else if (a[i] > second && a[i] != first)
        {
            second = a[i];
        }
    }

    printf("First Largest = %d\n", first);
    printf("Second Largest = %d\n", second);
}

void findMean(int a[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    printf("Mean = %.2f\n", (float)sum / n);
}

void findMedian(int a[], int n)
{
    int b[100];

    for (int i = 0; i < n; i++)
        b[i] = a[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    if (n % 2 == 0)
        printf("Median = %.2f\n", (b[n / 2 - 1] + b[n / 2]) / 2.0);
    else
        printf("Median = %d\n", b[n / 2]);
}

void standardDeviation(int a[], int n)
{
    float sum = 0, mean, variance = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    mean = sum / n;

    for (int i = 0; i < n; i++)
        variance += (a[i] - mean) * (a[i] - mean);

    variance /= n;

    printf("Standard Deviation = %.2f\n", sqrt(variance));
}

void findMode(int a[], int n)
{
    int mode = a[0];
    int maxCount = 1;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            mode = a[i];
        }
    }

    printf("Mode = %d\n", mode);
}

void removeDuplicates(int a[], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = i + 1; j < *n; j++)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < *n - 1; k++)
                    a[k] = a[k + 1];

                (*n)--;
                j--;
            }
        }
    }

    printf("Array after removing duplicates: ");

    for (int i = 0; i < *n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void reverseArray(int a[], int n)
{
    int i = 0, j = n - 1;

    while (i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }

    printf("Reversed array: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void partitionArray(int a[], int n, int pivot)
{
    int i = 0, j = n - 1;

    while (i <= j)
    {
        while (i < n && a[i] >= pivot)
            i++;

        while (j >= 0 && a[j] < pivot)
            j--;

        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    printf("Partitioned array: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int a[100], n, pivot;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n");

    findMax(a, n);
    findLargest(a, n);
    findMean(a, n);
    findMedian(a, n);
    standardDeviation(a, n);
    findMode(a, n);

    removeDuplicates(a, &n);

    reverseArray(a, n);

    printf("Enter pivot: ");
    scanf("%d", &pivot);

    partitionArray(a, n, pivot);

    return 0;
}