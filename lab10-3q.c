#include <stdio.h>

#define MAX 100

int parent[MAX];
int size[MAX];
int weight[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);

    if (ra == rb)
        return;

    parent[rb] = ra;
    size[ra] += size[rb];
    weight[ra] += weight[rb];
}

int main() {
    int V, E, K;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter size limit K: ");
    scanf("%d", &K);

    for (int i = 0; i < V; i++) {
        printf("Enter weight of vertex %d: ", i);
        scanf("%d", &weight[i]);

        parent[i] = i;
        size[i] = 1;
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        printf("Enter edge: ");
        scanf("%d %d", &u, &v);

        unite(u, v);

        int maxWeight = 0;

        for (int j = 0; j < V; j++) {
            if (find(j) == j && size[j] <= K) {
                if (weight[j] > maxWeight)
                    maxWeight = weight[j];
            }
        }

        printf("Maximum valid component weight = %d\n", maxWeight);
    }

    return 0;
}