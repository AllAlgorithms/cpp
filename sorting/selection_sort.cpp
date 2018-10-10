//
// C++ implementation of selection sort
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/sorting
// https://github.com/allalgorithms/cpp
//
// Contributed by: Rituparno Biswas
// Github: @roopbiswas
//
#include <iostream>

// Swap elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Implement selection sort
void selectionSort(int arr[], int n)
{
   int i, j, min_id;
   for (i = 0; i < n-1; i++)
   {
   		min_id=i;
   		for (j = i+1; j < n; j++)
   			if (arr[min_id] > arr[j])
   				min_id=j;
   			swap(&arr[i], &arr[min_id]);
   	}
}

// Function to print elements
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// test
int main()
{
	int arr[] = {46, 24, 33, 10, 2, 81, 50};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Unsorted array: \n");
	printArray(arr, n);
	selectionSort(arr, n);
  	printf("Sorted array: \n");
	printArray(arr, n);
  return 0;
}
