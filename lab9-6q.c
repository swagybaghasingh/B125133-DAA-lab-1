#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char ch;
    int freq;
} Character;

int main() {
    char str[MAX];
    int K;

    printf("Enter string: ");
    scanf("%s", str);

    printf("Enter K: ");
    scanf("%d", &K);

    int n = strlen(str);

    Character a[26];

    for (int i = 0; i < 26; i++) {
        a[i].ch = 'a' + i;
        a[i].freq = 0;
    }

    for (int i = 0; i < n; i++)
        a[str[i] - 'a'].freq++;

    char result[MAX];

    int last[26];

    for (int i = 0; i < 26; i++)
        last[i] = -K;

    for (int pos = 0; pos < n; pos++) {

        int best = -1;

        for (int i = 0; i < 26; i++) {
            if (a[i].freq > 0 &&
                pos - last[i] >= K) {

                if (best == -1 ||
                    a[i].freq > a[best].freq)
                    best = i;
            }
        }

        if (best == -1) {
            printf("Rearrangement not possible.\n");
            return 0;
        }

        result[pos] = a[best].ch;
        a[best].freq--;
        last[best] = pos;
    }

    result[n] = '\0';

    printf("Rearranged string = %s\n", result);

    return 0;
}