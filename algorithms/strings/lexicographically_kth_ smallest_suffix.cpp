#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Print the lexicographically kth smallest suffix of the string S.

int main()
{
    ll int i,j,k;
    string s;
    cin>>s>>k;
    string s1[s.size()];
    for(i=0;i<s.size();i++){                   //Storing all possibe suffix strings in s1
        for(j=i;j<s.size();j++){
            s1[i]+=s[j];
        }
    }
    
    sort(s1,s1+(s.size()));
    cout<<s1[k-1]<<endl;
    return 0;
}