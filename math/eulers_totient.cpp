#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	return (b > 0 ? gcd(b, a%b) : a);
}

unsigned int phi(unsigned int n) 
{ 
    unsigned int result = 1;
    for (int i = 2; i < n; ++i)
	  {
        if (gcd(i, n) == 1)
		    {
            result++;
		    }
	  }

    return result;
}

int main()
{
    int n;
    cin >> n;
    assert(n <= 1000000); // Assertion to ensure execution time is reasonable ( < 1second)

    cout << "Value of Euler's totient function for n is " << phi(n) << endl;

    return 0;
}
