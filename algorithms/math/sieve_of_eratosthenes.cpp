// this is a program to implement sieve algorithm to generate prime numbers.

//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define ios        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int prime[1000000]={0};
void sieve(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==0)
        {
            for(int j=2*i;j<=n;j+=i)
            prime[j]=1;
        }
    }
}
int main()
{
    ios

    int x;
    cin>>x;

    sieve(x);

    //now whichever i>1 has prime[i]==0 , is a prime.

    for(int i=2;i<=x;i++)
    {
        if(prime[i]==0)
        cout<<i<<" ";
    }
    
}
