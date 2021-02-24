#include<stdio.h>
int printNatural(int n);
int main()
{
    int n;
    scanf("%d",&n);    
    int sum=printNatural(n);
    printf("sum is=%d",sum);
    return 0;
}

int printNatural(int n)
{
   int sum=0;
   if(n==0)
     return 0;
   sum=sum+n;
   printNatural(n-1);
   return sum;
}