#include <stdio.h>

struct Result
{
    int min;
    int max;
};

struct Result findMinMax(int a[], int low, int high)
{
    struct Result result;
    struct Result leftResult;
    struct Result rightResult;

    // Only one element
    if (low == high)
    {
        result.min = a[low];
        result.max = a[low];
        return result;
    }

    // Two elements
    if (high == low + 1)
    {
        if (a[low] < a[high])
        {
            result.min = a[low];
            result.max = a[high];
        }
        else
        {
            result.min = a[high];
            result.max = a[low];
        }

        return result;
    }

    // Divide the array
    int mid = (low + high) / 2;

    // Find min and max in left half
    leftResult = findMinMax(a, low, mid);

    // Find min and max in right half
    rightResult = findMinMax(a, mid + 1, high);

    // Find overall maximum
    if (leftResult.max > rightResult.max)
        result.max = leftResult.max;
    else
        result.max = rightResult.max;

    // Find overall minimum
    if (leftResult.min < rightResult.min)
        result.min = leftResult.min;
    else
        result.min = rightResult.min;

    return result;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    struct Result result = findMinMax(a, 0, n - 1);

    printf("\n--- Result ---\n");
    printf("Minimum element = %d\n", result.min);
    printf("Maximum element = %d\n", result.max);

    return 0;
}