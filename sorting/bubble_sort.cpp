// C++ implementation of bubble sort
//
// Author: Carlos Abraham Hernandez

#include <iostream>

// Swap elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Implement bubble sort
void bubble_sort(int arr[], size_t n)
{
   for (size_t i = 0; i < n - 1; i++)
   {
	   	// last i elements are already in place
		for (size_t j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
   }
}

// A utility function to print an array of size n 
void print_array(int arr[], int n) 
{ 
   for (size_t i = 0; i < n; i++)
    {
       std::cout << arr[i] << " ";
    }
    std::cout << std::endl; 
} 

int main()
{
	int arr[] = {46, 24, 33, 10, 2, 81, 50};
	int n = sizeof(arr)/sizeof(arr[0]);
	std::cout << "Unsorted array:" << std::endl;
	print_array(arr, n);
	bubble_sort(arr, n);
  	std::cout << "Sorted array:" << std::endl;
	print_array(arr, n);
  	return 0;
}
