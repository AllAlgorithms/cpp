#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main()
{
    int sieve[10000000]={0};
    for(int i=2;i<10000000;i++)
    {
        if(sieve[i]==0)
        for(int j=1;j*i<10000000;j++)
        {
            if(sieve[i*j]==0)
              sieve[i*j]=i;

        }
    }
    long long int a[10000000];
    a[0]=0;
    a[1]=0;
    for(int i=2;i<10000000;i++)
        a[i]=a[i-1]+sieve[i];

    int t,n;
    cin>>t;
    while(t--)
    {
      cin>>n;
      cout<<a[n]<<"\n";
    }
}
