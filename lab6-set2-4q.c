#include <stdio.h>

#define MAX 100

void reverse(int a[], int l, int r)
{
    while (l < r)
    {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;

        l++;
        r--;
    }
}

void rotate(int a[], int l, int m, int r)
{
    if (l > m || m >= r)
        return;

    reverse(a, l, m);
    reverse(a, m + 1, r);
    reverse(a, l, r);
}

/*
   Stable partition:
   elements <= pivot are placed before
   elements > pivot.
*/

int stablePartition(int a[], int l, int r, int pivot)
{
    if (l == r)
    {
        if (a[l] <= pivot)
            return l + 1;

        return l;
    }

    int mid = (l + r) / 2;

    int leftEnd = stablePartition(a, l, mid, pivot);
    int rightEnd = stablePartition(a, mid + 1, r, pivot);

    /*
       Left part:
       [true elements][false elements]

       Right part:
       [true elements][false elements]

       Rotate:
       [left false][right true]
       becomes
       [right true][left false]
    */

    int leftFalse = leftEnd;
    int rightTrue = mid + 1;

    if (leftFalse <= mid && rightTrue < rightEnd)
    {
        rotate(a, leftFalse, mid, rightEnd - 1);
    }

    int countLeftTrue = leftEnd - l;
    int countRightTrue = rightEnd - (mid + 1);

    return l + countLeftTrue + countRightTrue;
}

void sortByReversal(int a[], int l, int r)
{
    if (l >= r)
        return;

    int min = a[l];
    int max = a[l];

    for (int i = l + 1; i <= r; i++)
    {
        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];
    }

    if (min == max)
        return;

    int pivot = (min + max) / 2;

    int mid = stablePartition(a, l, r, pivot);

    if (mid > l)
        sortByReversal(a, l, mid - 1);

    if (mid <= r)
        sortByReversal(a, mid, r);
}

int main()
{
    int n;
    int a[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter permutation:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Original permutation:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    sortByReversal(a, 0, n - 1);

    printf("Sorted permutation:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}