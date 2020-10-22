#include<iostream>
#include<vector>
using namespace std;
vector<int>get_factors(vector<int>&primes,int n)
{
    vector<int>ans;
    ans.clear();
    for(int i=0;i*i<=n;i++)
    {
        if(n%primes[i]==0)
        {
            ans.push_back(primes[i]);
            while(n%primes[i]==0)
            {
                n=n/primes[i];
            }

        }
    }
    if(n!=1)
    {
        ans.push_back(n);
    }
    return ans;
} 
vector<int>get_prime(vector<int>&prime,int n)
{
  for(int i=3;i<=1000;i+=2)
  {
    prime[i]=1;
  }
  //mark all the even number as non prime
  for(int i=3;i*i<=1000;i+=2)
  {
    if(prime[i]==1)
    {
        for(int j=i*i;j<=1000;j+=i)
        {
            prime[j]=0;
        }
    }
  }
  prime[0]=prime[1]=0;
  prime[2]=1;
  vector<int>fectors;
  for(int i=2;i<=1000;i++)
  {
   if(prime[i]==1)
   {
    fectors.push_back(i);
   }
  }
return fectors;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //first task to genrate prime fectors and store it
      vector<int>p(1000,0);
  //now we have all prime number till n
    int n;
    cin>>n;
    //enter n (the number you want to get prime fector)
    vector<int>primes=get_prime(p,n);
    vector<int>ans=get_factors(primes,n);
    cout<<"Prime Factors are :";
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
return 0;
}
