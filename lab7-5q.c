
#include <stdio.h>

int main() {
    int n;

    printf("Enter number of hiding spots: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Target can be hit immediately.\n");
    }
    else if (n == 2) {
        printf("A guaranteed strategy exists.\n");
        printf("Shoot spot 1, then spot 2.\n");
        printf("Maximum shots required: 2\n");
    }
    else {
        printf("No guaranteed strategy exists.\n");
        printf("The target can avoid the shooter indefinitely.\n");
    }

    return 0;
}
