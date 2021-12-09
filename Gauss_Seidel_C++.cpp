//C++ Program to Implement Gauss Seidel Method

#include<iostream>
#include<cmath>
using namespace std;
#define EPSILON 0.001  // till 3 correct decimal places


//Helper function
float findSum(int i,float a[50][51],int n)
{
     float sum=0;
     for(int j=0;j<n;j++)
     {  
       if(i!=j)  
         sum+=a[i][j];
     }
     return sum;
}

//checks if Gauss Seidel Method is applicable and return true if yes otherwise return false
bool isMethodApplicable(float a[50][51],int n)
{
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {

           if(fabs(a[i][i])>findSum(i,a,n))
              break;
           else  
              return false;   

       }
   }
   return true;
}

//prints the Value of Unknowns
void print(int iteration,float values[],int n) 
{
  cout<<"Iteration "<<iteration<< ": ";  
  for(int i=0;i<n;i++)
    cout<<"value["<<i+1<<"]= "<<values[i]<<" ";
  cout<<endl;
}


void findValues(float a[50][51],int maxIterations,float values_old[],int n)
{
    int i,j,k,iteration,flag=0;
    float ratio,sum=0;
    float values_new[n];
    //This loop is added for Gauss seidel ( not present in Jacobi method)
    for(int i=0;i<n;i++)
     values_new[i]=0;

    for(iteration=1;iteration<=maxIterations;iteration++)
    {
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                sum+=a[i][j]*values_new[j];   // in Gauss Jacobi, we took values_old[] here
            }
           
            values_new[i]=(a[i][n] - sum)/a[i][i];
        }
        //Now you have found the values of n unknowns for above iteration
        //Now check if your matching criteria satisfied , comparing with previous iteration values 
        for(k=0;k<n;k++)
        {
            if(fabs(values_old[k]-values_new[k])<EPSILON)
                continue;          
            else
            {
               flag=1;
               break;
            }
        } 
        if(flag==0)
        {
            print(iteration,values_new,n);  // print final values of unknowns  and return 
            return ;
        }
        flag=0; //resetting the flag
       
        print(iteration,values_new,n); //To print intermediate roots

        //copy new values of unknowns to old value array
        for(k=0;k<n;k++)
             values_old[k]=values_new[k];
    } //end of iteration loop
    print(iteration,values_new,n) ; 

} //end of findValues()

 
int main()
{
    int i,j,k,x,y,maxIterations,n;
    float ratio;
    cout<<"Enter no of Unknowns\n";
    cin>>n;
    cout<<"Enter no. of iterations\n";
    cin>>maxIterations;
    float a[50][51];
    float values[50];;

    cout<<"Enter the Augmented Matrix\n";
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n+1;j++)
        cin>>a[i][j];
    }

   if(!isMethodApplicable(a,n))
   {
        cout<<"\nGauss Seidel Method can't be applied";
        return 0;
   }
   cout<<"\nGauss Seidel Method is applicable\n\n";
   for(int i=0;i<n;i++)
     values[i]=0;
   findValues(a,maxIterations,values,n);
   return 0;
}



