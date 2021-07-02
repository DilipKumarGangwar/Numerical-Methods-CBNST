//Newton Backward Interploation Method
#include<stdio.h>
#include<math.h>

int main()
{
    float x,u1,u,y;
    int i,j,n,fact;
    printf("Enter no. of terms\n");
    scanf("%d",&n);
    float a[n][n+1];
    printf("Enter Values of X \n");
    for(i=0;i<n;i++)
          scanf("%f",&a[i][0]);
    printf("Enter Values of Y\n");
    for(i=0;i<n;i++)
          scanf("%f",&a[i][1]);
          
    printf("Enter value of x for which you want y\n");
    scanf("%f",&x);

    //Find the Difference Table    
    for(j=2;j<n+1;j++)
    {
        for(i=0;i<n-j+1;i++)
            a[i][j] = a[i+1][j-1]-a[i][j-1];
    }

    //Print the Difference Table
    printf("The Difference Table is as follows:\n");
    for(i=0;i<n;i++)
    {
     for(j=0;j<=n-i;j++)
        printf("%f ",a[i][j]);
     printf("\n");
    }
    
    //find u
    u= (x - a[n-1][0])/(a[1][0]-a[0][0]);
    y=a[n-1][1]; 
    //Initial k, u1, j
    u1=u;
    fact=1;
    j=2;  //corresponds to column no.
    for(i=n-2;i>=0;i--)
    {
        y=y+(u1*a[i][j])/fact;
        //Update k, u1, j
        fact=fact*j; 
        u1=u1*(u+(j-1));
        j++;
    }
    printf("\n\nValue at X=%g is = %f", x,y);
}