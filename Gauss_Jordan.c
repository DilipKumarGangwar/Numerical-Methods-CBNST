//C Program to Implement Gauss Jordan Method
#include<stdio.h>

int n;
//Converts the Augmented matrix to Diagonal form
void convertToDiagonal(float a[][n+1],int n)
{
    int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
         if(j!=i)
         {
             ratio=a[j][i]/a[i][i];
             for(k=0;k<n+1;k++)
                a[j][k]=a[j][k] -( ratio * a[i][k]);

             //print the Matrix after changed row (Intermediate forms)
             printf("Intermediate forms:\n");
             for( x=0;x<n;x++)
             {
               for(y=0;y<n+1;y++)
                  printf("%f ",a[x][y]);
               printf("\n");   
             }
             printf("\n");
             
         } 
      }
     }
}


//prints the Value of Unknowns
void printUnknowns(float a[][n+1],int n)
{  
   int i;
   printf("Values of unknowns are:\n");
   for(i=0;i<n;i++)
      printf("Value of Variable %d=%f\n",i,a[i][n]/a[i][i]);
   
}
int main()
{
    int i,j,k,x,y;
    float ratio;
    printf("Enter no of Unknowns\n");
    scanf("%d",&n);
    float a[n][n+1];
    printf("Enter the Augmented Matrix\n");
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n+1;j++)
        scanf("%f",&a[i][j]);
    }
    convertToDiagonal(a,n);
    printUnknowns(a,n); 
    return 0;
}
