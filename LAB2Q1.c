#include<stdio.h>
#include<math.h>

#define MAX 20

int n[MAX]={
10,20,30,40,50,
60,70,80,90,100,
200,300,400,500,
600,700,800,900,1000,2000
};

double constant[MAX];
double logarithmic[MAX];
double linear[MAX];
double nlogn[MAX];
double quadratic[MAX];

void calculateGrowth()
{
int i;

for(i=0;i<MAX;i++)
  
{
  
    constant[i]=1;
  
    logarithmic[i]=log2(n[i]);
  
    linear[i]=n[i];
  
    nlogn[i]=n[i]*log2(n[i]);
  
    quadratic[i]=n[i]*n[i];
  
}

}

void display()
{
int i;

printf("\n---------------------------------------------------------\n");
  
printf("n\tO(1)\tO(logn)\tO(n)\tO(nlogn)\tO(n^2)\n");
  
printf("---------------------------------------------------------\n");
  

  
for(i=0;i<MAX;i++)
  
{
  
    printf("%d\t%.0lf\t%.2lf\t\t%.0lf\t%.2lf\t\t%.0lf\n",
  
           n[i],
  
           constant[i],
  
           logarithmic[i],
  
           linear[i],
  
           nlogn[i],
  
           quadratic[i]);
  
}

}

void writeFile()
{
FILE *fp;

fp=fopen("growth.csv","w");
  

  
fprintf(fp,"n,O(1),O(logn),O(n),O(nlogn),O(n2)\n");
  

  
int i;
  

  
for(i=0;i<MAX;i++)
  
{
  
    fprintf(fp,"%d,%.0lf,%.2lf,%.0lf,%.2lf,%.0lf\n",
  
            n[i],
  
            constant[i],
  
            logarithmic[i],
  
            linear[i],
  
            nlogn[i],
  
            quadratic[i]);
  
}
  

  
fclose(fp);

}

int main()
{
printf("\nDICTIONARY OPERATION GROWTH ANALYSIS\n");
printf("=====================================\n");

calculateGrowth();
  

  
display();
  

  
writeFile();
  

  
printf("\nData successfully written into growth.csv\n");
  
printf("Open growth.csv in Microsoft Excel and plot a Line Graph.\n");
  

  
return 0;

}