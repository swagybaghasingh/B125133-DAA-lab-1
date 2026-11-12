#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXV 100
#define MAXE 500
#define INF 1000000000

typedef struct {
    int to;
    int weight;
} Edge;

Edge graph[MAXV][MAXE];
int degree[MAXV];

typedef struct {
    int vertex;
    int parity;
} State;

typedef struct {
    State data[MAXV * 2];
    int front, rear;
} Deque;

void initDeque(Deque *dq) {
    dq->front = MAXV;
    dq->rear = MAXV - 1;
}

int isEmpty(Deque *dq) {
    return dq->front > dq->rear;
}

void pushFront(Deque *dq, State s) {
    dq->data[--dq->front] = s;
}

void pushBack(Deque *dq, State s) {
    dq->data[++dq->rear] = s;
}

State popFront(Deque *dq) {
    return dq->data[dq->front++];
}

int main() {
    int V, E, S, C;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter source vertex: ");
    scanf("%d", &S);

    printf("Enter penalty C: ");
    scanf("%d", &C);

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][degree[u]].to = v;
        graph[u][degree[u]].weight = w;
        degree[u]++;
    }

    int dist[MAXV][2];

    for (int i = 0; i < V; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    Deque dq;
    initDeque(&dq);

    dist[S][0] = 0;

    State start = {S, 0};
    pushFront(&dq, start);

    while (!isEmpty(&dq)) {
        State current = popFront(&dq);

        int u = current.vertex;
        int parity = current.parity;

        for (int i = 0; i < degree[u]; i++) {
            int v = graph[u][i].to;
            int w = graph[u][i].weight;

            int newParity = parity ^ w;
            int newDist = dist[u][parity] + w;

            if (newDist < dist[v][newParity]) {
                dist[v][newParity] = newDist;

                State next = {v, newParity};

                if (w == 0)
                    pushFront(&dq, next);
                else
                    pushBack(&dq, next);
            }
        }
    }

    printf("\nMinimum effective cost from source %d:\n", S);

    for (int v = 0; v < V; v++) {
        int answer = INF;

        if (dist[v][0] != INF)
            answer = dist[v][0];

        if (dist[v][1] != INF)
            if (dist[v][1] + C < answer)
                answer = dist[v][1] + C;

        if (answer == INF)
            printf("Vertex %d : Unreachable\n", v);
        else
            printf("Vertex %d : %d\n", v, answer);
    }

    return 0;
}