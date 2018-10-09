#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      int hashs[n+1]={0,0};
      int a;
      for(int i=1;i<=n;i++)
       {  cin>>a;
          if(a<=n)
            hashs[a]++;
       } int count=-1;
       for(int i=0;i<=n;i++)
        if(hashs[i]==0)
       {
           count++;
       }
      cout<<count<<"\n";
  }
}
