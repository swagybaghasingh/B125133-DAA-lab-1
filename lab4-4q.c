#include <stdio.h>

struct Event {
    int time;
    int type;
};

void sort(struct Event e[],int n) {
    int i,j;
    struct Event t;

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(e[i].time>e[j].time) {
                t=e[i];
                e[i]=e[j];
                e[j]=t;
            }
}

int main() {
    struct Event e[200];
    int n,i,cur=0,max=0,time;

    printf("Enter number of people: ");
    scanf("%d",&n);

    printf("Enter entry and exit times:\n");

    for(i=0;i<n;i++) {
        scanf("%d%d",&e[2*i].time,&e[2*i+1].time);
        e[2*i].type=1;
        e[2*i+1].type=-1;
    }

    sort(e,2*n);

    for(i=0;i<2*n;i++) {
        cur+=e[i].type;

        if(cur>max) {
            max=cur;
            time=e[i].time;
        }
    }

    printf("Maximum people present = %d\n",max);
    printf("Time = %d\n",time);

    return 0;
}