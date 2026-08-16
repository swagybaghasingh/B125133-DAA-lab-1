#include <stdio.h>

int comparisons = 0;

/* 
   Returns the index of the defective coin.
   Returns -1 if no defective coin exists.
*/
int findDefective(int a[], int left, int right, int normalWeight)
{
    int n = right - left + 1;

    /* Only one coin */
    if (n == 1)
    {
        comparisons++;

        if (a[left] < normalWeight)
            return left;

        return -1;
    }

    int third = n / 3;

    int leftEnd = left + third - 1;
    int middleEnd = left + 2 * third - 1;

    int sum1 = 0;
    int sum2 = 0;

    /* Weight group 1 */
    for (int i = left; i <= leftEnd; i++)
        sum1 += a[i];

    /* Weight group 2 */
    for (int i = leftEnd + 1; i <= middleEnd; i++)
        sum2 += a[i];

    comparisons++;

    /*
       If group 1 is lighter,
       defective coin is in group 1.
    */
    if (sum1 < sum2)
    {
        return findDefective(a, left, leftEnd, normalWeight);
    }

    /*
       If group 2 is lighter,
       defective coin is in group 2.
    */
    else if (sum2 < sum1)
    {
        return findDefective(a,
                             leftEnd + 1,
                             middleEnd,
                             normalWeight);
    }

    /*
       If both groups have equal weight,
       defective coin is in group 3.
    */
    else
    {
        return findDefective(a,
                             middleEnd + 1,
                             right,
                             normalWeight);
    }
}

int main()
{
    int n;
    int normalWeight;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    printf("Enter weight of a normal coin: ");
    scanf("%d", &normalWeight);

    int a[n];

    printf("Enter weights of %d coins:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    comparisons = 0;

    int result = findDefective(a, 0, n - 1, normalWeight);

    printf("\n--- Result ---\n");

    if (result == -1)
    {
        printf("No defective coin found.\n");
    }
    else
    {
        printf("Defective coin found at position %d\n",
               result + 1);
    }

    printf("Number of weighings/comparisons = %d\n",
           comparisons);

    return 0;
}