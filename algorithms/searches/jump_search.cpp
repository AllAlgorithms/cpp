//
// C++ program to implement Jump Search
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/searches/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Bharat Reddy
// Github: @Bharat-Reddy
//
#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int x, int n)
{
    // Finding block size to be jumped
    int step = sqrt(n);

    // Finding the block where element is
    // present (if it is present)
    int prev = 0;
    while (arr[min(step, n)-1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[prev] < x)
    {
        prev++;

        // If we reached next block or end of
        // array, element is not present.
        if (prev == min(step, n))
            return -1;
    }
    // If element is found
    if (arr[prev] == x)
        return prev;

    return -1;
}

// Driver program to test function
int main()
{
    int n,i;
    cout<<"Eneter size of array : ";
    cin>>n;
    cout<<"Enter elements of array"<<endl;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cout<<"Enter key to be searched : ";
    int key;
    cin>>key;

    // Find the index of 'x' using Jump Search
    int index = jumpSearch(a, key, n);

    // Print the index where 'x' is located
    cout << "\nNumber " << key << " is at index " << index;
    return 0;
}
