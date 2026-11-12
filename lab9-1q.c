#include <stdio.h>

typedef struct {
    double value, weight, lambda;
    double density;
} Item;

int main() {
    int n;
    double W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item a[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value, weight and decay rate for item %d: ",
               i + 1);
        scanf("%lf %lf %lf",
              &a[i].value, &a[i].weight, &a[i].lambda);

        a[i].density = a[i].value / a[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%lf", &W);

    /* Sort by base density */
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].density < a[j].density) {
                Item temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    double total = 0;
    double time = 0;

    printf("\nSelected items:\n");

    for (int i = 0; i < n && W > 0; i++) {
        double effectiveDensity =
            a[i].density - a[i].lambda * time;

        if (effectiveDensity <= 0)
            continue;

        double amount = (a[i].weight <= W)
                       ? a[i].weight : W;

        total += amount * effectiveDensity;
        W -= amount;
        time += amount;

        printf("Item %d -> %.2lf units, Effective Density = %.2lf\n",
               i + 1, amount, effectiveDensity);
    }

    printf("\nMaximum value = %.2lf\n", total);

    return 0;
}