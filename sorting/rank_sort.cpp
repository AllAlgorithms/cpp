 	
#include <iostream>
#include <math.h>
using namespace std;

    void rankSort(int A[], int low, int high)
    {
        int R[high-low+1];
        for(int i=0; i<high-low+1; i++)
            R[i] = 1;
        
        for(int i=low+1; i<=high; i++)
        {
            for(int j=low;j<i;j++)
            {
                if(A[i] >= A[j])
                    R[i-low]++;
            
                else
                    R[j-low]++;
            }
        }
        
        int U[high-low+1];
        for(int i=0;i<high-low+1;i++)
            U[R[i]] = A[i+low];
        
        for(int i=0;i<high-low+1;i++)
            A[i+low] = U[i+1];
    }
int mod(int i)
{
    if (i<0)
        i=-i;
    return i;
}

int main()
{
    int n;
    cout<<"enter the total no. of entries"<<endl;
    cin>>n;
    int houses[n];
    cout<<"enter the entries"<<endl;
    for (int i = 0; i < n; ++i)
    {
        cin>>houses[i];
    }
   
    rankSort(houses,0,n-1);
    for(int i=0;i<n;i++)
        cout<<houses[i] << " ";
    return 0;
}