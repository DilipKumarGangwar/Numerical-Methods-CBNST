//C Program to Implement Gauss Elimination Method
#include<stdio.h>

int n;
//Converts the Augmented matrix to Upper Triangular Matrix form
void convertToUpperTriangular(float a[][n+1],int n)
{
    int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
         if(j>i)
         {
             ratio=a[j][i]/a[i][i];
             for(k=0;k<n+1;k++)
                a[j][k]=a[j][k] -( ratio * a[i][k]);

             //print the Matrix after changed row (Intermediate forms)
             printf("Intermediate forms:\n");
             for( x=0;x<n;x++)
             {
               for(y=0;y<n+1;y++)
                  printf("%.2f ",a[x][y]);
               printf("\n");   
             }
             printf("\n");
             
         } 
      }
     }
}

//Performs Back Substitution to find values of Unknowns
void ApplyBackSubstitution(float a[][n+1],float value[],int n)
{   
    int i,j;
    float sum;
    value[n-1]=a[n-1][n]/a[n-1][n-1]; 

    for(i=n-2;i>=0;i--)
    {
        sum=0;
        for(j=i+1;j<n;j++)
            sum=sum+a[i][j]*value[j];  
        value[i] = (a[i][n]-sum)/a[i][i];
    } 
}

//prints the Value of Unknowns
void print(float value[],int n)
{  
   int i;
   printf("Values of unknowns are:\n");
   for(i=0;i<n;i++)
      printf("Value[%d]=%f\n",i,value[i]);
   
}
int main()
{
    int i,j,k,x,y;
    float sum,ratio;
    printf("Enter no of Unknowns\n");
    scanf("%d",&n);
    float a[n][n+1],value[n];
    printf("Enter the Augmented Matrix\n");
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n+1;j++)
        scanf("%f",&a[i][j]);
    }
    convertToUpperTriangular(a,n);
    ApplyBackSubstitution(a,value,n);
    print(value,n); 
    return 0;
}
