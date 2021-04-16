//C Program to Implement Trapezoidal Rule

#include<stdio.h>

float findValueAt(float x)
{
    return x*x*x;
}
int main()
{
    int n;
    float i,a,b,sum=0,h;
    //Input
    printf("Enter Value of a and b\n");
    scanf("%f%f",&a,&b);
    printf("Enter no. of Intervals\n");
    scanf("%d",&n);

    //....................Computations .....................

    h=(b-a)/n;
    sum = findValueAt(a) +findValueAt(b);
    for(i=a+h;i<b;i=i+h)
       sum = sum + 2*findValueAt(i);
    sum = (h * sum)/2;
    //Print the Output
    printf("\nValue of The integral  = %f",sum);    
    
}