#include <iostream>
using namespace std;

int checkPrimeNumber(int);

int main()
{
  int n;

  cout << "Enter a positive  integer: ";
  cin >> n;
  
  if(checkPrimeNumber(n) == 0)
    cout << n << " is a prime number.";
  else
    cout << n << " is not a prime number.";
  return 0;
}
int checkPrimeNumber(int n)
{
  bool flag = false;

  for(int i = 2; i <= n/2; ++i)
  {
      if(n%i == 0)
      {
          flag = true;
          break;
      }
  }
  return flag;
}