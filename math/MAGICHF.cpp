#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,t,s,i,a,b,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>s;
        ans=x;
        for(i=0;i<s;i++)
           {
               cin>>a>>b;
               if(ans==a)
                ans=b;
               else if(ans==b)
                ans=a;
           }
           cout<<ans<<"\n";
    }
}
