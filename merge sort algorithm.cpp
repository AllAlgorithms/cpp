/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#define ll long long
#include<iostream>
using namespace std;
//Arpcoder

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(ll arr[], ll l, ll m, ll r)
{
	ll i, j, k;
	ll n1 = m - l + 1;
	ll n2 = r - m;

	/* create temp arrays */
	ll L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(ll arr[], ll l, ll r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		ll m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(ll A[], ll size)
{
	ll i;
	for (i = 0; i < size; i++)
		printf("%lld ", A[i]);
	printf("\n");
}

/* Driver code */
int main()
{
	ll n;cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
