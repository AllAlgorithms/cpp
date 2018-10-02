/*
C++ implementation of heap sort
Author:Divya Gupta
Input:An array of integers
Output: Gives an array sorted in ascending order
Time Complexity:O(nlogn)
*/
#include<iostream>
using namespace std;
void swap(int* num1, int* num2) 
{ 
	int temp = *num1; 
	*num1 = *num2; 
	*num2 = temp; 
}
void heapify(int A[], int high, int low)
{
	int r = 2*low + 2; 
    int largest = low;  
    int l = 2*low + 1; 
    if (l < high && A[l] > A[largest])
        largest = l;
   	if (r < high && A[r] > A[largest])
       	largest = r;
    if (largest != low)
    {
    	swap(&A[low],&A[largest]);
    	heapify(A, high, largest);
    }
}
void heapSort(int A[], int low, int high)
{
	for (int i = high / 2 - 1; i >= 0; i--)
	    heapify(A, high, i);
   	for (int i=high-1; i>=0; i--)
   	{
   	    swap(&A[0],&A[i]);
   	    heapify(A, i, 0);
   	}
}

int main()
{
    cout<<"Enter number of elements in an array"<<endl;
    int n;
    cin>>n; 
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    heapSort(a,0,n);
    cout<<"Sorted array"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
}

