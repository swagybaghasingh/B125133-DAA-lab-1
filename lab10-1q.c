#include <stdio.h>

#define MAX 100

int parent[MAX], parity[MAX];

int find(int x) {
    if (parent[x] == x)
        return x;

    int p = parent[x];
    parent[x] = find(parent[x]);
    parity[x] ^= parity[p];

    return parent[x];
}

int addEdge(int u, int v) {
    int ru = find(u);
    int rv = find(v);

    if (ru == rv) {
        if (parity[u] == parity[v])
            return 0;
        return 1;
    }

    parent[ru] = rv;
    parity[ru] = parity[u] ^ parity[v] ^ 1;

    return 1;
}

int main() {
    int V, E, u, v;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        parity[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        printf("Enter edge: ");
        scanf("%d %d", &u, &v);

        if (addEdge(u, v))
            printf("Edge (%d,%d) added. Graph remains bipartite.\n", u, v);
        else
            printf("Edge (%d,%d) violates bipartiteness. Skipped.\n", u, v);
    }

    return 0;
}