#include <stdio.h>
#include <string.h>

#define MAXN 100000
#define MAXL 11

char words[MAXN][MAXL];
int visitedA[MAXN];
int visitedB[MAXN];

int queueA[MAXN];
int queueB[MAXN];

int N, L;

int differByOne(char *a, char *b) {
    int count = 0;

    for (int i = 0; i < L; i++) {
        if (a[i] != b[i])
            count++;

        if (count > 1)
            return 0;
    }

    return count == 1;
}

int findWord(char *word) {
    for (int i = 0; i < N; i++) {
        if (strcmp(words[i], word) == 0)
            return i;
    }

    return -1;
}

int expandQueue(
    int queue[],
    int *front,
    int *rear,
    int visitedThis[],
    int visitedOther[],
    int distThis[],
    int distOther[]
) {
    int levelSize = *rear - *front;

    while (levelSize--) {

        int u = queue[(*front)++];

        for (int v = 0; v < N; v++) {

            if (!visitedThis[v] &&
                differByOne(words[u], words[v])) {

                visitedThis[v] = 1;
                distThis[v] = distThis[u] + 1;

                if (visitedOther[v])
                    return distThis[v] + distOther[v];

                queue[(*rear)++] = v;
            }
        }
    }

    return -1;
}

int main() {
    char A[MAXL], B[MAXL];

    printf("Enter number of words: ");
    scanf("%d", &N);

    printf("Enter word length: ");
    scanf("%d", &L);

    printf("Enter dictionary words:\n");

    for (int i = 0; i < N; i++)
        scanf("%s", words[i]);

    printf("Enter starting word: ");
    scanf("%s", A);

    printf("Enter target word: ");
    scanf("%s", B);

    int start = findWord(A);
    int target = findWord(B);

    if (target == -1) {
        printf("Target word is not present in dictionary.\n");
        return 0;
    }

    if (start == -1) {
        printf("Starting word is not present in dictionary.\n");
        return 0;
    }

    if (start == target) {
        printf("Minimum mutations: 0\n");
        return 0;
    }

    int distA[MAXN] = {0};
    int distB[MAXN] = {0};

    int frontA = 0, rearA = 0;
    int frontB = 0, rearB = 0;

    queueA[rearA++] = start;
    queueB[rearB++] = target;

    visitedA[start] = 1;
    visitedB[target] = 1;

    distA[start] = 0;
    distB[target] = 0;

    int answer = -1;

    while (frontA < rearA && frontB < rearB) {

        if (rearA - frontA <= rearB - frontB) {

            answer = expandQueue(
                queueA,
                &frontA,
                &rearA,
                visitedA,
                visitedB,
                distA,
                distB
            );

        } else {

            answer = expandQueue(
                queueB,
                &frontB,
                &rearB,
                visitedB,
                visitedA,
                distB,
                distA
            );
        }

        if (answer != -1)
            break;
    }

    if (answer == -1)
        printf("No valid transformation exists.\n");
    else
        printf("Minimum mutations: %d\n", answer);

    return 0;
}