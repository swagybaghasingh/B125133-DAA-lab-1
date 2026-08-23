#include <stdio.h>

struct Event {
    int point;
    int type;
};

void sort(struct Event e[],int n) {
    int i,j;
    struct Event t;

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(e[i].point>e[j].point ||
              (e[i].point==e[j].point && e[i].type<e[j].type)) {
                t=e[i];
                e[i]=e[j];
                e[j]=t;
            }
}

int main() {
    struct Event e[200];
    int n,i,cur=0,max=0,p;

    printf("Enter number of intervals: ");
    scanf("%d",&n);

    printf("Enter intervals:\n");

    for(i=0;i<n;i++) {
        scanf("%d%d",&e[2*i].point,&e[2*i+1].point);

        e[2*i].type=1;       // start
        e[2*i+1].type=-1;   // end
    }

    sort(e,2*n);

    for(i=0;i<2*n;i++) {
        cur+=e[i].type;

        if(cur>max) {
            max=cur;
            p=e[i].point;
        }
    }

    printf("Point = %d\n",p);
    printf("Maximum overlapping intervals = %d\n",max);

    return 0;
}