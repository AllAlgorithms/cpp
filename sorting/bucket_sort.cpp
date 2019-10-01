//
// C++ implementation of bucket sort.
//
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Simon Faillace Mullen
// Github: @macmullen
//
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

// A utility function to print an array of size n.
// Implemented by Carlos Abraham Hernandez in bubble_sort.cpp
void print_array(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Given an array "arr" of size "n", this function sorts its numbers
// using the algorithm of Bucket Sort.
void bucket_sort(int arr[], size_t n, int number_of_buckets)
{
    // Find the maximum element of the array
    int* max = std::max_element(arr, arr+n);
    // Calculate the divider value dividing the maximum element and number of buckets.
    int divider = std::ceil(float(*max + 1) / float(number_of_buckets) );
    // Create the buckets array.
    std::vector<std::vector<int>> buckets;
    buckets.resize(number_of_buckets);

    // Place every number into a corresponding bucket.
    for (size_t i = 0; i < n; i++)
    {
        int j = floor(arr[i] / divider);
        buckets[j].push_back(arr[i]);
    }

    // Sort every bucket.
    int index = 0;
    for (size_t i = 0; i < number_of_buckets; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
        // Place the sorted numbers into the original array.
        for(int number : buckets[i])
        {
            arr[index] = number;
            index++;
        }
    }
}

int main()
{
    int arr[] = {22, 45, 12, 8, 10, 6, 72, 81, 33, 18, 50, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Unsorted array: ";
    print_array(arr, n);
    bucket_sort(arr, n, 10);
    std::cout << "Sorted array: ";
    print_array(arr, n);
    return 0;
}