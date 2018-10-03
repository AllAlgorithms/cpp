// Binary Search implemented in C++
// Carlos Abraham Hernandez
// algorithms.abranhe.com/searches/binary-search
// repl.it/@abranhe/Binary-Search

#include <iostream>

int binary_search(int arr[], int l, int r, int key)
{
	if(r < l)
	{ // key is not found in arr
		return -1;
	}

	size_t middle = l + (r - l) / 2;
	if(key == arr[middle])
	{
		return middle;
	}
	if(key > arr[middle])
	{
		return binary_search(arr, middle + 1, r, key);
	}
	// key must be found in left subarray or not found at all
	return binary_search(arr, l, middle - 1, key);
}

int main(int argc, char const *argv[])
{
	int n, key;
	std::cout << "Enter size of array: ";
	std::cin >> n;

	std::cout << "Enter array elements, sorted: ";
	int* arr = new int[n];
  	for (size_t i = 0; i < n; ++i)
	{
		std::cin >> arr[i];	
	}

	std::cout << "Enter search key: ";
	std::cin >> key;	
	
  	int res = binary_search(arr, 0, n - 1, key);
	
  	if(res >= 0)
	{
		std::cout << "Key " << key << " found at index " << res << std::endl;
	}
	else
	{
		std::cout << "Could not find key " << key << "in array" << std::endl;
	}
	delete[] arr;
	return 0;
}
