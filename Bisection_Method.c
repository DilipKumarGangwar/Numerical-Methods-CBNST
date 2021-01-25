//Bisection Method (Without Allowed Error Concept)
#include<stdio.h>
float findValueAt(float x)
{
   return x*x*x - 2*x -5;
}

float bisect(float x1,float x2)
{
    return (x1+x2)/2;
}

int main()
{
    int maxIteration,i=1;
    float x1,x2,x;
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);

//......Compute x1 and x2............. 
   
   do
   {
        printf("Enter the value of x1 and x2(starting boundary)");
        scanf("%f%f",&x1,&x2);
        if(findValueAt(x1)*findValueAt(x2)>0)
        {
           printf("Roots are Invalid\n");
           continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",x1,x2);
            break;

        }
    } while(1);

 //..........Find root............   
   //x1 x2 ->finalised
    while(i<=maxIteration)
    {
      x = bisect(x1,x2);   //find the mid point
      if(findValueAt(x)*findValueAt(x1)<0)
         x2=x;  //x2 is shifted   
      else if(findValueAt(x)*findValueAt(x2)<0)
         x1=x;  //x1 is shifted
     printf("Iterations=%d  Roots=%f\n",i,x);   
      
      i++; 
    }
    printf("Root=%f  Total Iterations=%d",x,--i);

    return 0;
}

//Bisection Method (With Allowed Error Concept)
#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001
float findValueAt(float x)
{
   return x*x*x - 2*x -5;
}

float bisect(float x1,float x2)
{
    return (x1+x2)/2;
}
int main()
{
    int maxIteration,i=1;
    float x1,x2,x3,x;
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);
    
   do
   {
        printf("Enter the value of x1 and x2(starting boundary->Initial Roots)");
        scanf("%f%f",&x1,&x2);
        if(findValueAt(x1)*findValueAt(x2)>0)
        {
           printf("Roots are Invalid\n");
           continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",x1,x2);
            break;

        }
    } while(1);

    //find the mid point
    x = bisect(x1,x2);   

    do
    {
      if(findValueAt(x)*findValueAt(x1)<0)
         x2=x;    
      else
         x1=x;
      printf("Iterations=%d  Roots=%f\n",i,x);   
      x3 = bisect(x1,x2);  
      if(fabs(x3-x)<EPSILON)
      {
          //print root
          printf("Root=%f  Total Iterations=%d",x,i);
          return 0;

      }
      x=x3;  //v.imp
      i++; 
    }while(i<=maxIteration);
    printf("Root=%f  Total Iterations=%d",x,--i);

    return 0;
}