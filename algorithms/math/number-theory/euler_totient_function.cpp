/*Problem Statement:-
	Given a number n, find the count of numbers from [1,n] that are
	relatively prime to n i.e. gcd(n,x)=1
Solution:-
	using euler totient function
*/
#include<iostream>

using  namespace std;

int phi(int n)						//less efficient but easy to understand
{
	float result=n;
	for(int f=2;f*f<=n;f++)
		if(n%f==0)
		{
			while(n%f==0)
				n/=f;
			result*=(1.0-(1.0/(float)f));
		}
	if(n>1)
		result*=(1.0-(1.0/(float)n));
	return int(result);
}

int phi2(int n)						//more efficient because of reduced number of multiplications
{
	int result=n;
	for(int f=2;f*f<=n;f++)
		if(n%f==0)
		{
			while(n%f==0)
				n/=f;
			result-=result/f;
		}
	if(n>1)
		result-=result/n;
	return result;
}

int main()
{
	cout<<"\nEnter a number : ";
	int n;
	cin>>n;
	cout<<"\nCount of numbers from [1,n] that are relatively prime to n are : "<<phi2(n)<<endl;

return 0;
}
