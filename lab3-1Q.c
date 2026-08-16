#include <stdio.h>

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1;
    int count = 0;

    while (low <= high)
    {
        count++;

        int mid = low + (high - low) / 2;

        if (a[mid] == key)
            return count;

        if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return count;
}

int ternarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1;
    int count = 0;

    while (low <= high)
    {
        count++;

        int third = (high - low) / 3;

        int mid1 = low + third;
        int mid2 = high - third;

        if (a[mid1] == key)
            return count;

        if (a[mid2] == key)
            return count;

        if (key < a[mid1])
            high = mid1 - 1;
        else if (key > a[mid2])
            low = mid2 + 1;
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return count;
}

int main()
{
    FILE *fp;

    fp = fopen("search_data.dat", "w");

    if (fp == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    printf("n\tBinary\tTernary\n");

    for (int n = 10; n <= 1000; n += 10)
    {
        int a[n];

        for (int i = 0; i < n; i++)
            a[i] = i + 1;

        /*
           Search for the last element.
           This gives a consistent worst-case-style test.
        */

        int key = n;

        int binary = binarySearch(a, n, key);
        int ternary = ternarySearch(a, n, key);

        fprintf(fp, "%d %d %d\n", n, binary, ternary);

        printf("%d\t%d\t%d\n", n, binary, ternary);
    }

    fclose(fp);

    printf("\nData saved to search_data.dat\n");

    return 0;
}