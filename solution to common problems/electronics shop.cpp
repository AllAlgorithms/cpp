#include <cmath>
#include <cstdio>
//https://www.hackerrank.com/challenges/electronics-shop/problem

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long int s,n,m,arrn[100000],arrm[100000];
    long int ans=-1;
    cin>>s;
    cin>>n;
    cin>>m;
    long int i=0;
    for(;i<n;i++)
    {
        cin>>arrn[i];
    }
    long int j=0;
    for(;j<m;j++)
    {
        cin>>arrm[j];
    }
    long int k=0;
    long int l=0;
    for(;k<n;k++)
    {
        for(int l=0;l<m;l++)
        {
            if((arrn[k]+arrm[l])>ans&&(arrn[k]+arrm[l])<=s)
                ans=arrn[k]+arrm[l];
        }
    }
    cout<<ans;
    return 0;
}
