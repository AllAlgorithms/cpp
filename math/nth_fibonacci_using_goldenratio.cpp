//
// CPP program to find n-th Fibonacci number 
// More documentation about the algorithm
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Mohbius
// Github: @mohbius
//
#include <iostream>
#include <cstdlib> 
#include <cmath>
using namespace std; 
  
// Approximate value of golden ratio 
double PHI = 1.6180339; 
  
// Fibonacci numbers upto n = 5 
int f[6] = { 0, 1, 1, 2, 3, 5 }; 
  
// Function to find nth 
// Fibonacci number 
int fib (int n) 
{ 
    // Fibonacci numbers for n < 6 
    if (n < 6) 
        return f[n]; 
  
    // Else start counting from  
    // 5th term 
    int t = 5, fn = 5; 
  
    while (t < n) { 
         fn = round(fn * PHI); 
         t++; 
    } 
  
    return fn;    
} 
  
int main() 
{ 
    std::cout << fib(9) << std::endl; // 34
    std::cout << fib(8) << std::endl; // 21
    std::cout << fib(7) << std::endl; // 13
    return 0; 
} 
