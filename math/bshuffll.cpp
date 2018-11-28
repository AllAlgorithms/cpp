//
// Bshuffll Implementation
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/
// https://github.com/allalgorithms/cpp
//
// Contributed by: shashank3395
// Github: @shashank3395
//
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==1)
       { cout<<1<<"\n"<<1;}
    else if(n%2==0)
    {
        for(int i=1;i<=n;i++)
            cout<<i<<" ";
            cout<<"\n";
        for(int i=n;i>=1;i--)
                cout<<i<<" ";

    }
        else if(n%2==1)
        {
            for(int i=1;i<=n;i++)
                cout<<i<<" ";
            cout<<"\n";
            for(int i=n;i>=1;i--)
                cout<<i<<" ";

        }
}
