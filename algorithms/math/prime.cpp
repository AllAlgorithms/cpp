#include<iostream>
using namespace std;
int main()
{int n,flag;
cin>>n;
//to check whether a number is prime or not
for(int i=2;i<n;i++){
 if(n%i==0)
 flag++;}
 if(flag>0)
 cout<<"number is not prime"<<endl;
 else cout<<"number is prime"<<endl;
 return 0;
 }
