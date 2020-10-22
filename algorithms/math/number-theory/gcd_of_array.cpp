//
// C++ program to find GCD of an array of integers
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/math
// https://github.com/allalgorithms/cpp
//
// Contributed by: Bharat Reddy
// Github: @Bharat-Reddy
//
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = gcd(arr[i], result);

    return result;
}

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter elements of array"<<endl;
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout << findGCD(a, n) << endl;
    return 0;
}
