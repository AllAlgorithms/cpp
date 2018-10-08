#include <bits/stdc++.h>

using namespace std;

long long int fast_modulo_exponentiation(long long int n,
                                         long long int exp,
                                         long long int modulo)
{
  unsigned int bitsInLongLong = sizeof(long long int) * 8;
  vector<long long int> exponents(bitsInLongLong);
  exponents[0] = n % modulo;
  
  for(int i=1; i < bitsInLongLong; ++i)
  {
    exponents[i] = exponents[i-1] * exponents[i-1] % modulo;
  }
  
  long long int result = 1LL;
  for(int i=0; i < bitsInLongLong; ++i)
  {
    if((exp >> i) & 1)
    {
      result = result * exponents[i] % modulo;
    }
  }
  
  return result;
}

int main()
{
  long long int n, exponent, modulo;
  cin >> n >> exponent >> modulo;
  
  /*
   * The assertion below makes sure that the modulo below is small enough
   * to prevent an overflow during the multiplication.
   * One such value that is frequently used is 10^9+7.
   */
  assert( ((long long int) sqrt(LLONG_MAX)) >= modulo );
  
  long long int result = fast_modulo_exponentiation(n, exponent, modulo);
  cout << "Fast modulo multiplication result:" << result << endl;
  
  return 0;
}
