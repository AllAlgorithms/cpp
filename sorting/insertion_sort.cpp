// C++ implementation of insertion sort
//
// Author: Andres Langberg


#include <iostream>

/* Function to sort an array using insertion sort*/
void insertion_sort(int arr[], int n) 
{ 
   int key;
   size_t j;
   for (size_t i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i - 1; 
  
       /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j + 1] = arr[j]; 
           j--; 
       } 
       arr[j + 1] = key; 
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
  
  
  
/* Driver program to test insertion sort */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6}; 
    size_t n = sizeof(arr) / sizeof(arr[0]); 
    std::cout << "Unsorted array:" << std::endl;
    print_array(arr, n); 
    insertion_sort(arr, n); 
    std::cout << "Sorted array:" << std::endl;
    print_array(arr, n); 
    return 0; 
} 
