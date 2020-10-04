#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
long long p1,p2,k;
cin>>p1>>p2>>k;
long long r = (p1+p2)%(2*k);
if(r>=0&&r<k)
cout<<"CHEF"<<"\n";
else
cout<<"COOK"<<"\n";
}
return 0;
}
