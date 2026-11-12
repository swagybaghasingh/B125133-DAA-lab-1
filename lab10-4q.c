#include <stdio.h>

#define MAX 100

int parent[MAX];
int active[MAX];
int weight[MAX];
int compWeight[MAX];

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
    compWeight[ra] += compWeight[rb];
}

int main() {
    int V, E;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter vertex weights:\n");
    for (int i = 0; i < V; i++)
        scanf("%d", &weight[i]);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    int edges[MAX][2];

    printf("Enter edges:\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d", &edges[i][0], &edges[i][1]);

    int P[MAX];

    printf("Enter deletion order:\n");
    for (int i = 0; i < V; i++)
        scanf("%d", &P[i]);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        active[i] = 0;
        compWeight[i] = weight[i];
    }

    int answer[MAX];
    int maxWeight = 0;

    for (int i = V - 1; i >= 0; i--) {

        int x = P[i];

        active[x] = 1;
        parent[x] = x;
        compWeight[x] = weight[x];

        if (weight[x] > maxWeight)
            maxWeight = weight[x];

        for (int j = 0; j < E; j++) {
            int a = edges[j][0];
            int b = edges[j][1];

            if (a == x && active[b])
                unite(a, b);

            if (b == x && active[a])
                unite(a, b);
        }

        for (int j = 0; j < V; j++) {
            if (active[j] && find(j) == j) {
                if (compWeight[j] > maxWeight)
                    maxWeight = compWeight[j];
            }
        }

        answer[i] = maxWeight;
    }

    printf("\nMaximum component weight after each deletion:\n");

    for (int i = 0; i < V; i++)
        printf("%d ", answer[i]);

    return 0;
}