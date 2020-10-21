//
// C/C++ program to check whether the given string is a palindrome
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/strings
// https://github.com/allalgorithms/cpp
//
// Contributed by: Sankalp Godghate
// Github: @sankalp24
//
#include <iostream>
using namespace std;
// A function to check if a string str is palindrome 
bool isPalindrome(const string& str) 
{ 
	// Start from left and right ends of str
	int l = 0; 
	int r = str.size() - 1; 

	// Keep comparing characters while they are same.
	while (r > l) 
	{ 
		if (str[l] != str[r]) 
		{ 
			return false;
		} 
		l++;
		r--;
	} 
	return true;
} 

// Driver program to test above function 
int main() 
{ 
	string str;
   	cin >> str;
   	if(isPalindrome(str)) {
		cout << str << " is a palindrome.";
	} else {
		cout << str << " is not a palindrome.";
	}
	return 0; 
}
