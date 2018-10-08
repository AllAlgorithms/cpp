#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
  int sqrtN = sqrt(n);
  for(int i=2; i <= sqrtN; ++i)
  {
    if(n % i == 0)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  int n;
  cin >> n;

  assert(n <= 1000000000);// Check if the given integer is too large
  
  cout << (isPrime(n) ? "Is Prime" : "Is Not Prime") << endl;

  return 0;
}
