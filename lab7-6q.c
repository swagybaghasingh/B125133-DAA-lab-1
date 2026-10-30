
#include <stdio.h>
#include <stdlib.h>

struct Event {
    int year;
    int type;
};

int compare(const void *a, const void *b) {
    struct Event *x = (struct Event *)a;
    struct Event *y = (struct Event *)b;

    if (x->year != y->year)
        return x->year - y->year;

    return x->type - y->type;
}

int main() {
    int n, i, alive = 0;
    int maximum = 0, bestYear = 0;

    struct Event e[200];

    printf("Enter number of scientists: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int birth, death;

        printf("Enter birth and death year: ");
        scanf("%d %d", &birth, &death);

        e[2*i].year = birth;
        e[2*i].type = 1;

        e[2*i+1].year = death;
        e[2*i+1].type = -1;
    }

    qsort(e, 2*n, sizeof(struct Event), compare);

    for (i = 0; i < 2*n; i++) {
        alive += e[i].type;

        if (e[i].type == 1 && alive > maximum) {
            maximum = alive;
            bestYear = e[i].year;
        }
    }

    printf("\nYear with maximum scientists alive: %d\n",
           bestYear);
    printf("Maximum scientists alive: %d\n", maximum);

    return 0;
}
