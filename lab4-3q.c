#include <stdio.h>

int found = 0;

void solve(int a[],int n,int k,int start,int sum,int T) {
    int i;

    if(k==0) {
        if(sum==T) found=1;
        return;
    }

    for(i=start;i<=n-k;i++)
        solve(a,n,k-1,i+1,sum+a[i],T);
}

int main() {
    int a[100],n,k,T,i;

    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    printf("Enter k and T: ");
    scanf("%d%d",&k,&T);

    solve(a,n,k,0,0,T);

    if(found)
        printf("%d elements with sum %d exist\n",k,T);
    else
        printf("No such combination exists\n");

    return 0;
}