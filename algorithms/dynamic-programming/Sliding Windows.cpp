////////////////////////////////////////////////////////////////////
///////////////WINDOW SLIDING TECHNIQUE/////////////////////////////
////ref- https://www.geeksforgeeks.org/window-sliding-technique/////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define beastslayer ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

//Q- Find the maximum sum of a k length subarray from a given array

int main()
{
    beastslayer;

    int arr[10]={5,1,-9,2,3,5,7,11,12,50};
    int k;   //Length of subarrays
    cin>>k;

    int max_sum=0;        //Final answer to be found
    for(int i=0;i<k;++i)
        max_sum+=arr[i];

    int window_sum=max_sum;  //current window pane sum

    for(int i=k;i<10;++i)
    {
        window_sum+=arr[i]-arr[i-k];    //going to every element and removing the one (i-k)th for creating new pale window
        max_sum=max(window_sum,max_sum);
    }
    cout<<max_sum<<endl;

    return 0;
}
