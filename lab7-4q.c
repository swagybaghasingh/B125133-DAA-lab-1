
#include <stdio.h>

#define MAX 1048576

int queue[MAX], parent[MAX], move[MAX];

int main() {
    int n, i, start, front = 0, rear = 0;
    int goal = 0, found = 0;

    printf("Enter number of switches (max 20): ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Invalid number of switches\n");
        return 0;
    }

    start = (1 << n) - 1;

    for (i = 0; i < (1 << n); i++)
        parent[i] = -1;

    queue[rear++] = start;
    parent[start] = start;

    while (front < rear) {
        int s = queue[front++];

        if (s == goal) {
            found = 1;
            break;
        }

        for (i = 0; i < n; i++) {
            int valid;

            if (i == n - 1)
                valid = 1;
            else
                valid = ((s >> (i + 1)) & ((1 << (n - i - 1)) - 1))
                        == 1;

            if (valid) {
                int next = s ^ (1 << i);

                if (parent[next] == -1) {
                    parent[next] = s;
                    move[next] = i + 1;
                    queue[rear++] = next;
                }
            }
        }
    }

    if (found) {
        int path[100], count = 0;
        int s = goal;

        while (s != start) {
            path[count++] = move[s];
            s = parent[s];
        }

        printf("Minimum moves: %d\n", count);
        printf("Switches toggled: ");

        for (i = count - 1; i >= 0; i--)
            printf("%d ", path[i]);

        printf("\n");
    } else {
        printf("Solution not found\n");
    }

    return 0;
}
