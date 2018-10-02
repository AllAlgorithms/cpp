// Ternary Search implemented in C++
//Sriram Desai

#include <iostream>
#include <vector>
using namespace std;

vector<int> ar;

int ternary_search(int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        if(ar[mid1] == x)
            return mid1;
        if(ar[mid2] == x)
            return mid2;
        if(x<ar[mid1])
            return ternary_search(l,mid1-1,x);
        else if(x>ar[mid2])
            return ternary_search(mid2+1,r,x);
        else
            return ternary_search(mid1+1,mid2-1,x);

    }
    return -1;
}

int main(int argc, char const *argv[])
{
	int n, key;
	cout << "Enter size of array: ";
	cin >> n;
	cout << "Enter array elements: ";
	
    for (int i = 0; i < n; ++i)
	{
        int t;
		cin>>t;
        ar.push_back(t);	
	}
	cout << "Enter search key: ";
	cin>>key;	
	
    int res = ternary_search(0, n-1, key);
	
    if(res != -1)
		cout<< key << " found at index " << res << endl;
	else
		cout << key << " not found" << endl;
	return 0;
}
