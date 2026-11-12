#include <stdio.h>

typedef struct {
    int distance;
    int fuel;
} Station;

void sort(Station a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].distance > a[j].distance) {
                Station temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int n, D, F;

    printf("Enter target distance: ");
    scanf("%d", &D);

    printf("Enter initial fuel: ");
    scanf("%d", &F);

    printf("Enter number of stations: ");
    scanf("%d", &n);

    Station a[n];

    for (int i = 0; i < n; i++) {
        printf("Enter distance and fuel of station %d: ",
               i + 1);
        scanf("%d %d",
              &a[i].distance,
              &a[i].fuel);
    }

    sort(a, n);

    int fuel = F;
    int stops = 0;

    int maxFuel[100];
    int top = -1;

    for (int i = 0; i < n; i++) {

        fuel -= a[i].distance -
                (i == 0 ? 0 : a[i - 1].distance);

        while (fuel < 0 && top >= 0) {
            fuel += maxFuel[top--];
            stops++;
        }

        if (fuel < 0) {
            printf("Target cannot be reached.\n");
            return 0;
        }

        maxFuel[++top] = a[i].fuel;
    }

    fuel -= D - a[n - 1].distance;

    while (fuel < 0 && top >= 0) {
        fuel += maxFuel[top--];
        stops++;
    }

    if (fuel < 0)
        printf("Target cannot be reached.\n");
    else
        printf("Minimum refuelling stops = %d\n", stops);

    return 0;
}