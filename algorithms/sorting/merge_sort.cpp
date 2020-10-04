//
// C++ implementation of merge sort
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/sorting
// https://github.com/allalgorithms/cpp
//
// Contributed by: Carlos Abraham Hernandez
// Github: @abranhe (abraham@abranhe.com)
//
#include <iostream>

// Merge the two half into a sorted data.
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int* L = new int[n1];
    int* R = new int[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
// A utility function to print an array of size n
void print_array(int arr[], int n)
{
   for (size_t i = 0; i < n; i++)
    {
       std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Unsorted array:" << std::endl;
    print_array(arr, arr_size);
    merge_sort(arr, 0, arr_size - 1);
    std::cout << "Sorted array:" << std::endl;
    print_array(arr, arr_size);
    return 0;
}
