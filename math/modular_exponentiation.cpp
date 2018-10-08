// modular exponentiation implemented in C++
//Author : Rituparno Biswas

//Given three numbers x, y and p, compute (power(x,y)) % p. where power(a,b) calculates a to power of b 


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll power(ll x, ll y, ll p)
{
	if(x==0)
		return 0;
	if(y==0)
		return 1;
	if (y%2==0)
	{
		ll g=power(x,y/2,p);
		return (g*g)%p;
	}
	else
	{
		ll g=power(x,y/2,p);
		return (x*(g*g)%p)%p;
	}
}

int main() 
{ 
   ll x = 2,y = 5, p = 13; 
   printf("Power is %lld", power(x, y, p)); 
   return 0; 
} 