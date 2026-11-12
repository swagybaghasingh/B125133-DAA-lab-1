#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int parent[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);

    if (ra != rb)
        parent[rb] = ra;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, m;

    printf("Enter n: ");
    scanf("%d", &n);

    int A[MAX];

    printf("Enter permutation:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("Enter number of allowed swaps: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int u, v;

        scanf("%d %d", &u, &v);
        unite(u, v);
    }

    for (int i = 0; i < n; i++) {

        int root = find(i);

        int elements[MAX];
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (find(j) == root)
                elements[count++] = A[j];
        }

        qsort(elements, count, sizeof(int), compare);

        int pos = 0;

        for (int j = 0; j < i; j++) {
            if (find(j) == root)
                pos++;
        }

        A[i] = elements[pos];
    }

    printf("Lexicographically smallest permutation:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}