
// C++ program to demonstrate Factorial Algorithm
// The All Algorithms Project
// https://allalgorithms.com/math
// https://github.com/allalgorithms/cpp
// Contributed by: Pablo Trinidad
// Github: @pablotrinidad


#include <bits/stdc++.h>
using namespace std;

int factorial(int n) 
{
    if (n <= 0)
    {
        return 1;    
    } 
    else
    {
       return n * factorial(n - 1);
    }
    
}

int main()
{
    int n;
    cout << "Enter an integer n to compute its factorial: "<<endl;
    cin >> n;
    int r = factorial(n);
    cout << n << "! = " << r << endl;
    return 0;
}
