/*
Program :To find the sum of square of  
binomial coefficient. 

This Program is contributed by Abhishek Jaiswal
*/
#include <bits/stdc++.h>
using namespace std;

int factorial(int begin, int end)
{
    int num = 1;
    for (int i = begin; i <= end; i++)
        num *= i;

    return num;
}

int square(int n)
{
    return factorial(n + 1, 2 * n) / factorial(1, n);
}

int main()
{
    int n;
    cout << "Enter the number :";
    cin >> n;
    cout << "The Sum of Square is " << square(n) << endl;
    return 0;
}

