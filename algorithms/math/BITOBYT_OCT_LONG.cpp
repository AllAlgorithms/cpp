#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n;
cin>>n;
int r = n%26;
int q = n/26;
if(r>=1&&r<=2)
cout<<(long long)pow(2,q)<<"\t"<<0<<"\t"<<0<<"\n";
else if(r>2&&r<=10)
cout<<0<<"\t"<<(long long)pow(2,q)<<"\t"<<0<<"\n";
else if(r>10&&r<=25)
cout<<0<<"\t"<<0<<"\t"<<(long long)pow(2,q)<<"\n";
else if(r==0)
cout<<0<<"\t"<<0<<"\t"<<(long long)pow(2,q-1)<<"\n";
}
return 0;
}
