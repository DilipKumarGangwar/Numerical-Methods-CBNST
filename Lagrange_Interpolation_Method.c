//Lagrange's Interpolation Method
#include<stdio.h>

int main()
{
    int n;
    printf("Enter no. of terms\n");
    scanf("%d",&n);
    float X[n],Y[n],x,sum=0,term;
    int i,j;
   
    printf("Enter Values of X \n");
    for(i=0;i<n;i++)
          scanf("%f",&X[i]);
    printf("Enter Values of Y\n");
    for(i=0;i<n;i++)
          scanf("%f",&Y[i]);
          
    printf("Enter value of x for which you want y\n");
    scanf("%f",&x);

    // Applying the Formula  
    for(i=0;i<n;i++)
    {
        term=1;
        for(j=0;j<n;j++)
        {   
            if(i!=j)
               term = term * ((x - X[j])/(X[i]-X[j]));
        }
        sum=sum + term * Y[i];    
    }
    printf("\nValue at X=%g is = %f", x,sum);
}