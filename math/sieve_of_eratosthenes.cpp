#include <bits/stdc++.h>

using namespace std;

int sieveOfEratosthenes(int n, vector<int>& primes)
{
  vector<bool> isPrime(n + 1, true);
  
  primes.clear();
  for(int i=2; i <= n; ++i)
  {
    if(isPrime[i])
    {
      primes.push_back(i);
      for(int j=i + i; j <= n; j += i)
      {
        isPrime[j] = false;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  
  /*
   * Assert that the input is not too high, which would cause the algorithm to run slowly
   * (i.e. execution time could exceed 1 seconds)
   */
  assert(n <= 1000000);
  
  vector<int> primes;
  sieveOfEratosthenes(n, primes);
  
  cout << "Found primes:" << endl;
  for(int i=0; i < primes.size(); ++i)
  {
    cout << primes[i] << endl;
  }

  return 0;
}
