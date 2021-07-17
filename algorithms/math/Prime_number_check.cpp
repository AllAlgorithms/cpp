#include <assert.h>
#include <iostream>


bool checkIfPrimeNumber(unsigned int number);
void test_checkPrimeNumber_();


bool isPrimeNumber(unsigned int number) {

  if (number == 1)
    return false;

  for (int divisor = 2; divisor < number; divisor++)
    if (number % divisor == 0)
      return false; 

  return true;
}

void test_checkPrimeNumber_() {

  assert(isPrimeNumber(2) == true);
  assert(isPrimeNumber(3) == true);
  assert(isPrimeNumber(13) == true);
  assert(isPrimeNumber(59) == true);

  assert(isPrimeNumber(96) == false);
  assert(isPrimeNumber(124) == false);
  assert(isPrimeNumber(1) == false);  
}

int main() {

  test_checkPrimeNumber_();

  return 0;
}