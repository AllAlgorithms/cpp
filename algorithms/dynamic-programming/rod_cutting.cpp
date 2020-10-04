#include<iostream>
#include<climits>
 
using namespace std;
 
int rodCutting(int n, int value[])
{
    int i,j;
 

    int result[n+1];
 
    result[0]=0;
 
    for(i=1;i<=n;i++)
    {
        result[i]=INT_MIN;
 
        for(j=0;j<i;j++)
        {
            result[i]=max(result[i],value[j]+result[i-(j+1)]);
        }
    }
 
 
    return result[n];
}
 
int main()
{
    int n;
    cout<<"Enter the length of the rod"<<endl;
    cin>>n;
 
    int value[n];
    cout<<"Enter the values of pieces of rod of all size"<<endl;
 
    for(int i=0;i<n;i++)
        cin>>value[i];
 
    cout<<"Maximum obtainable value by cutting up the rod in many pieces are"<<endl;
    cout<<rodCutting(n,value);
 
    cout<<endl;
    return 0;
}
