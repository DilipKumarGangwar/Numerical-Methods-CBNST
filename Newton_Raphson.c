//C Program to Implement Newton Raphson Method
#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001

float f(float x)
{
    return x*x*x - 3*x -5;
}

float differentiate(float x)
{
    return 3*x*x - 3;
}

int main()
{
    int maxIteration,i;
    float x1,x2,x,x0;
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);

//......Compute x1 and x2............. 
   
   do
   {
        printf("Enter the value of x1 and x2(starting boundary)");
        scanf("%f%f",&x1,&x2);
        if(f(x1)*f(x2)>0)
        {
           printf("Boundary Values are Invalid\n");
           continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",x1,x2);
            break;
        }
    } while(1);

    //find x0
    if(fabs(f(x1)) < fabs(f(x2)))
        x0 = x1;
    else
        x1 = x2;    

    //Apply Successive approximation to find the root b/w x1 and x2
    //..........Find root............   
    for(i=1;i<=maxIteration;i++)
    {
      x = x0 - (f(x0)/differentiate(x0));  
      
      if(fabs(x-x0)<EPSILON)
      {       
            printf("Iterations=%d  Final Root=%f\n",i,x);
           return 0;
      }      
      printf("Iterations=%d  Roots=%f\n",i,x); 
      x0=x;
    }
    printf("Root=%f  Total Iterations=%d",x,--i);
    return 0;
}