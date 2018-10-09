#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int k,n;
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n>>k;
    char str[n];
    int a[n];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      if(a[i]<=k)
      {
          str[i]='1';
          k-=a[i];
      }
      else
      {
          str[i]='0';


      }
    }
    for(int i=0;i<n;i++)
        cout<<str[i];
    cout<<"\n";

}
}
