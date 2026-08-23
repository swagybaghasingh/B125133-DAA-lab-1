#include <stdio.h>

void sort(int a[],int n) {
    int i,j,t;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i]>a[j]) {
                t=a[i]; a[i]=a[j]; a[j]=t;
            }
}

int binary(int a[],int n,int x) {
    int l=0,r=n-1,m;
    while(l<=r) {
        m=(l+r)/2;
        if(a[m]==x) return 1;
        if(a[m]<x) l=m+1;
        else r=m-1;
    }
    return 0;
}

int main() {
    int a[100],b[100],n,x,i;

    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter S1: ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    printf("Enter S2: ");
    for(i=0;i<n;i++) scanf("%d",&b[i]);

    printf("Enter x: ");
    scanf("%d",&x);

    sort(b,n);

    for(i=0;i<n;i++)
        if(binary(b,n,x-a[i])) {
            printf("Pair found: %d + %d = %d\n",
                   a[i],x-a[i],x);
            return 0;
        }

    printf("No pair found\n");
    return 0;
}