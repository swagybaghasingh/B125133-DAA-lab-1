#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    char str1[100], str2[100];
    int dp[100][100];
    int m, n, i, j;
    char lcs[100];
    int index;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    m = strlen(str1);
    n = strlen(str2);

    for (i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }

    for (j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    index = dp[m][n];
    lcs[index] = '\0';

    i = m;
    j = n;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("Length of LCS = %d\n", dp[m][n]);
    printf("LCS = %s\n", lcs);

    return 0;
}