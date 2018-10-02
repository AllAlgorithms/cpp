#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n=12;

	while(n%2==0)
	{
		cout<<"2 ";
		n=n/2;
	}
	for(int i=3;i<sqrt(n);i=i+2)
	{
		while(n%i==0)
		{
			cout<<i<<" ";
			n=n/i;
		}
	}
	if(n>1)
		cout<<n;
}
