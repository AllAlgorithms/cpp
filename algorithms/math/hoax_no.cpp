
// CPP code to check if a number is a hoax 
// number or not. 
#include <bits/stdc++.h> 
using namespace std; 
// Function to find distinct prime factors 
// of given number n 
vector<int> primeFactors(int n) 
{ 
    vector<int> res; 
    if (n % 2 == 0) { 
        while (n % 2 == 0) 
            n = n / 2; 
        res.push_back(2); 
    } 
  
    // n is odd at this point, since it is no 
    // longer divisible by 2. So we can test 
    // only for the odd numbers, whether they 
    // are factors of n 
    for (int i = 3; i <= sqrt(n); i = i + 2) { 
  
        // Check if i is prime factor 
        if (n % i == 0) { 
            while (n % i == 0) 
                n = n / i; 
            res.push_back(i); 
        } 
    } 
  
    // This condition is to handle the case 
    // when n is a prime number greater than 2 
    if (n > 2) 
        res.push_back(n); 
    return res; 
} 
  
// Function to calculate sum of digits of 
// distinct prime factors of given number n 
// and sum of digits of number n and compare 
// the sums obtained 
bool isHoax(int n) 
{  
    // Distinct prime factors of n are being 
    // stored in vector pf 
    vector<int> pf = primeFactors(n); 
      
    // If n is a prime number, it cannot be a 
    // hoax number 
    if (pf[0] == n) 
        return false; 
      
    // Finding sum of digits of distinct prime 
    // factors of the number n 
    int all_pf_sum = 0;     
    for (int i = 0; i < pf.size(); i++) { 
  
        // Finding sum of digits in current 
        // prime factor pf[i].  
        int pf_sum; 
        for (pf_sum = 0; pf[i] > 0;  
             pf_sum += pf[i] % 10, pf[i] /= 10) 
            ; 
  
        all_pf_sum += pf_sum; 
    } 
  
    // Finding sum of digits of number n 
    int sum_n; 
    for (sum_n = 0; n > 0; sum_n += n % 10, 
                                  n /= 10) 
        ; 
  
    // Comparing the two calculated sums 
    return sum_n == all_pf_sum; 
} 
  
// Driver Method 
int main() 
{ 
    int n = 84; //Example input. This number is hoax number.
    if (isHoax(n)) 
        cout << "A Hoax Number\n"; 
    else
        cout << "Not a Hoax Number\n"; 
    return 0; 
} 
