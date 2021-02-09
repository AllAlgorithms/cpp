#include<iostream>
using namespace std;
int main()
{
    int n,i,l,r,ans;
    int arr[]={4,5,3,2,5};
    cin>>n;
    int temp[5];
    temp[0]=arr[0];
    for(i=1;i<5;i++)
    {
        temp[i]=temp[i-1]+arr[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>l>>r;
        if(l==0)
            cout<<temp[r]<<endl;
        else
        {
            ans=temp[r]-temp[l-1];
            cout<<ans<<endl;
        }
    }
    return 0;
}
