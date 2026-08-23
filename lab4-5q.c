#include <stdio.h>

struct Interval {
    int start,end;
};

void sort(struct Interval a[],int n) {
    int i,j;
    struct Interval t;

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i].start>a[j].start) {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
}

int main() {
    struct Interval a[100];
    int n,i,s,e;

    printf("Enter number of intervals: ");
    scanf("%d",&n);

    printf("Enter intervals:\n");
    for(i=0;i<n;i++)
        scanf("%d%d",&a[i].start,&a[i].end);

    sort(a,n);

    s=a[0].start;
    e=a[0].end;

    printf("Merged intervals: ");

    for(i=1;i<n;i++) {
        if(a[i].start<=e) {
            if(a[i].end>e)
                e=a[i].end;
        }
        else {
            printf("(%d,%d) ",s,e);
            s=a[i].start;
            e=a[i].end;
        }
    }

    printf("(%d,%d)\n",s,e);

    return 0;
}