#include<iostream>

using namespace std;

// A function to swap values using call by reference.
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// A function implementing shaker sort.
void ShakerSort(int a[], int n)
{
	int i, j, k;
	for(i = 0; i < n;)
	{
		// First phase for ascending highest value to the highest unsorted index.
		for(j = i+1; j < n; j++)
		{
			if(a[j] < a[j-1])
				swap(&a[j], &a[j-1]);
		}
		// Decrementing highest index.
		n--;

		// Second phase for descending lowest value to the lowest unsorted index.
		for(k = n-1; k > i; k--)
		{
			if(a[k] < a[k-1])
				swap(&a[k], &a[k-1]);
		}
		// Incrementing lowest index.
		i++;
	}
}

int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;

	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}

	ShakerSort(arr, n);

	// Printing the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
		cout<<"->"<<arr[i];

	return 0;
}
