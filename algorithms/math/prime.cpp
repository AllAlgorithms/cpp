#include<iostream>
using namespace std;
int main(){
 int n;
 cin>>n;
 //to check whether a number is prime or not
 bool isPrime=true;
 for(int i = 2 ;i <= n/2; i++){
     if( n%i == 0){
     isPrime=false;
     break;
     }
 }
 if(isPrime) cout<<"Number is Prime"<<endl;
 else cout<<"Number is not prime"<<endl;
 return 0;
 }
