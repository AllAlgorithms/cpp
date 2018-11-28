//
// C++ program to find LCM of n elements
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

typedef long long int ll;


int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Returns LCM of array elements
ll findlcm(int arr[], int n)
{

    ll ans = arr[0];

    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));

    return ans;
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
    printf("%lld\n", findlcm(a, n));
    return 0;
}
