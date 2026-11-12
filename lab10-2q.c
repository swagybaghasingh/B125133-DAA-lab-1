#include <stdio.h>

#define MAX 1000

int parent[MAX], rankArr[MAX];
int grid[20][20];

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

    if (rankArr[ra] < rankArr[rb])
        parent[ra] = rb;
    else if (rankArr[ra] > rankArr[rb])
        parent[rb] = ra;
    else {
        parent[rb] = ra;
        rankArr[ra]++;
    }
}

int main() {
    int R, C, K;
    int r, c;
    int components = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &R, &C);

    printf("Enter number of operations: ");
    scanf("%d", &K);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            grid[i][j] = 0;

    for (int i = 0; i < R * C; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int k = 0; k < K; k++) {
        printf("Enter land position: ");
        scanf("%d %d", &r, &c);

        if (grid[r][c] == 1) {
            printf("Number of islands = %d\n", components);
            continue;
        }

        grid[r][c] = 1;
        components++;

        int id = r * C + c;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < R &&
                nc >= 0 && nc < C &&
                grid[nr][nc] == 1) {

                int nid = nr * C + nc;

                if (find(id) != find(nid)) {
                    unite(id, nid);
                    components--;
                }
            }
        }

        printf("Number of islands = %d\n", components);
    }

    return 0;
}