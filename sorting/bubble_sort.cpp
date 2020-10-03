// C++ implementation of Bubble Sort(Optimised Solution).
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Abhishek Jaiswal
// Github: @Abhishek-iiit
//
#include<stdio.h>
#include<iostream>

using namespace std;

void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   bool changed; 
   for (i = 0; i < n-1; i++) 
   { 
     changed = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           swap(arr[j],arr[j+1]); 
            changed = true; 
        } 
     } 
     if (changed == false)
        break; 
   } 
} 

int main()
{
    int n;
    cout<<"Input the total size :"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Input the number one-by-one :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubbleSort(arr,n);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}