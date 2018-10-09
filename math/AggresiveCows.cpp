#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int hash[100000];
int hash1[100000];
int main() {
    int t;
    cin>>t;
    while(t--)
    {int n,m;
    cin>>n>>m;
    int a[n],i;
    for(i=0;i<n;i++)
    {cin>>a[i];
    if(a[i]<0)
        hash1[-1*a[i]]++;
        else
        hash[a[i]]++;
    }
    int ans=0;
    for(i=-100000;i<100000;i++)
    {if(i<0&&m-i<0)
       {if(i==m-i)
    ans+=hash1[-1*i]*(hash1[-1*(m-i)]-1);
    else
    ans+=hash1[-1*i]*hash1[-1*(m-i)];
    }
    else if(i<0&&m-i>=0)
         {if(i==m-i)
    ans+=hash1[-1*i]*(hash[m-i]-1);
    else
    ans+=hash1[-1*i]*hash[m-i];
    }
    else if(i>=0&&m-i<0)
         {if(i==m-i)
    ans+=hash[i]*(hash1[-1*(m-i)]-1);
    else
    ans+=hash[i]*hash1[-1*(m-i)];
    }
    else if(i>=0&&m-i>=0)
         {if(i==m-i)
    ans+=hash[i]*(hash[m-i]-1);
    else
    ans+=hash[i]*hash[m-i];
    }
    }
    ans/=2;
    cout<<ans<<"\n";
    }
   	return 0;
}
