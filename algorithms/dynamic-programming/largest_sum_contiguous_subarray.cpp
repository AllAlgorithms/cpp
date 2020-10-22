/*
Author : AMEY GONDHALEKAR
*/

#include<iostream>
using namespace std;

int maxSubArraySum(int arr[], int size)
{
    int maxsofar = arr[0];
    int currentmax = arr[0];

    for (int i = 1; i < size; i++)
    {
        currentmax = max(arr[i], currentmax+arr[i]);
        maxsofar = max(maxsofar, currentmax);
    }
    return maxsofar;
}


int main()
{
    // Fast IO
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    int arr[] = {6,-2, -1, 5, -1, -4, 1, 6, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = maxSubArraySum(arr, n);
    cout << "Maximum contiguous sum is " << sum;
    return 0;
}
