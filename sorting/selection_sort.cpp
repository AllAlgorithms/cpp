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

void selectionSort(int *array, int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;   
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;
         swap(array[i], array[imin]);
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
    selectionSort(arr,n);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}