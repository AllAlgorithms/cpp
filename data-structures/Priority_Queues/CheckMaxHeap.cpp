/*

Problem:
Given an array of integers, check whether it represents max-heap or not.
Return true or false.


*/


#include<bits/stdc++.h>
using namespace std;

bool checkMaxHeap(int arr[], int n){

    int loopSize = ((n-1)-1)/2;
	int j = 0;
	while(j <= loopSize) {
		int parent = j;
		int left = (2*parent)+1;
		int right = (2*parent)+2;
		
		bool ok = false;
		if(left < n) {
			if(arr[left] <= arr[parent])
				ok = true;
			else {
				return false;
			}
		}
		
		if(right < n) {
			if(arr[right] <= arr[parent])
				ok = true;
			else {
				return false;
			}
		}
		j++;	
	}
	return true;
}

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
}



