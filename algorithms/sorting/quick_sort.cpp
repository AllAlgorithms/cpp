//
// C++ implementation of quick sort
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/sorting
// https://github.com/allalgorithms/cpp
//
// Contributed by: Nikunj Taneja
// Github: @underscoreorcus
//
#include <iostream>
#include <vector>

void quick_sort(std::vector<int>&, size_t, size_t);
int partition(std::vector<int>&, size_t, size_t);

void quick_sort(std::vector<int>& arr, size_t start, size_t end)
{
    if(start < end)
    {
        int pivot = partition(arr, start, end);
        quick_sort(arr, start, pivot);
        quick_sort(arr, pivot + 1, end);
    }
}


int partition(std::vector<int>& arr, size_t start, size_t end)
{
    int x = arr[start];
    int i = start;
    for(size_t j = start + 1; j < end; j++)
    {
        if(arr[j]<=x)
	    {
            i=i+1;
	        std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i], arr[start]);
    return i;
}


void print_vector(std::vector<int>& arr)
{
   for (size_t i = 0; i < arr.size(); i++)
    {
       std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> arr = {10,9,8,7,6,5,4,3,2,1};
    int start = 0;
    int end = arr.size();
    std::cout << "Unsorted array:" << std::endl;
    print_vector(arr);
    quick_sort(arr, start, end);
    std::cout << "Sorted array:" << std::endl;
    print_vector(arr);
}
