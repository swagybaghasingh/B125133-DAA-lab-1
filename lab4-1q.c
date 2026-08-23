#include <stdio.h>

struct Item {
    int num;
    char color;
};

int main() {
    int n, i;
    struct Item a[100];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter number and color(R/B/Y):\n");
    for(i=0;i<n;i++)
        scanf("%d %c",&a[i].num,&a[i].color);

    printf("Sorted by color:\n");

    for(i=0;i<n;i++)
        if(a[i].color=='R')
            printf("%d R\n",a[i].num);

    for(i=0;i<n;i++)
        if(a[i].color=='B')
            printf("%d B\n",a[i].num);

    for(i=0;i<n;i++)
        if(a[i].color=='Y')
            printf("%d Y\n",a[i].num);

    return 0;
}