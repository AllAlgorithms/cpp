// C++ program to demonstrate Basic Euclidean Algorithm 
// Author Bharat Reddy

#include <bits/stdc++.h> 
using namespace std; 
  

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
int main() 
{ 
    int a,b;
    cout<<"Enter 2 numbers : ";
    cin>>a>>b;
    int g_c_d = gcd(a,b);
    cout<<"GCD is <<g_c_d<<endl;
    return 0; 
} 