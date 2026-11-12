#include <stdio.h>

#define MAXV 100
#define MAXE 500
#define MAXK 50

int graph[MAXV][MAXV];
int owner[MAXV];
int dist[MAXV];

int queue[MAXV];
int front, rear;

int main() {
    int V, E;
    int K, R;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        int u, v;

        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter number of hubs: ");
    scanf("%d", &K);

    int hubs[MAXK];

    printf("Enter hub vertices:\n");

    for (int i = 0; i < K; i++) {
        scanf("%d", &hubs[i]);
    }

    printf("Enter radius R: ");
    scanf("%d", &R);

    for (int i = 0; i < V; i++) {
        owner[i] = -1;
        dist[i] = -1;
    }

    front = 0;
    rear = 0;

    /*
       Insert hubs in increasing index order.
       This automatically provides deterministic
       tie-breaking.
    */
    for (int i = 0; i < K; i++) {
        int h = hubs[i];

        if (dist[h] == -1) {
            dist[h] = 0;
            owner[h] = i + 1;
            queue[rear++] = h;
        }
    }

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < V; v++) {

            if (graph[u][v] == 1) {

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    owner[v] = owner[u];

                    queue[rear++] = v;
                }
                else if (dist[v] == dist[u] + 1 &&
                         owner[u] < owner[v]) {

                    owner[v] = owner[u];
                }
            }
        }
    }

    printf("\nVertex\tOwner\tDistance\n");

    for (int i = 0; i < V; i++) {

        if (dist[i] == -1 || dist[i] > R)
            printf("%d\t-1\t-1\n", i);
        else
            printf("%d\t%d\t%d\n",
                   i, owner[i], dist[i]);
    }

    return 0;
}