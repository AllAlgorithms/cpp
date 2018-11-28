//
// C++ program to implement Linear Search
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/searches/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Bharat Reddy
// Github: @Bharat-Reddy
//
#include<bits/stdc++.h>
using namespace std;

int linear_search(int a[], int n, int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key) return i+1;
	}
	return -1;
}

int main()
{
	int n,i;
	cout<<"Eneter size of array : ";
	cin>>n;
	cout<<"Enter elements of array"<<endl;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter key to be searched : ";
	int key;
	cin>>key;
	int res = linear_search(a,n,key);
	if(res==-1)
	{
		cout<<key <<" not found"<<endl;
	}
	else
	{
		cout<<key<<" found at index"<<res<<endl;
	}
	return 0;
}
