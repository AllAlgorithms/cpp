// A recursive program to test whether a given 
// string can be segmented into space separated 
// words in dictionary 
#include <iostream> 
using namespace std; 

/* A utility function to check whether a word is 
present in dictionary or not. An array of strings 
is used for dictionary. Using array of strings for 
dictionary is definitely not a good idea. We have 
used for simplicity of the program*/
int dictionaryContains(string word) 
{ 
	string dictionary[] = {"mobile","samsung","sam","sung", 
							"man","mango","icecream","and", 
							"go","i","like","ice","cream"}; 
	int size = sizeof(dictionary)/sizeof(dictionary[0]); 
	for (int i = 0; i < size; i++) 
		if (dictionary[i].compare(word) == 0) 
		return true; 
	return false; 
} 

// returns true if string can be segmented into space 
// separated words, otherwise returns false 
bool wordBreak(string str) 
{ 
	int size = str.size(); 

	// Base case 
	if (size == 0) return true; 

	// Try all prefixes of lengths from 1 to size 
	for (int i=1; i<=size; i++) 
	{ 
		// The parameter for dictionaryContains is 
		// str.substr(0, i) which is prefix (of input 
		// string) of length 'i'. We first check whether 
		// current prefix is in dictionary. Then we 
		// recursively check for remaining string 
		// str.substr(i, size-i) which is suffix of 
		// length size-i 
		if (dictionaryContains( str.substr(0, i) ) && 
			wordBreak( str.substr(i, size-i) )) 
			return true; 
	} 

	// If we have tried all prefixes and 
	// none of them worked 
	return false; 
} 

// Driver program to test above functions 
int main() 
{ 
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n"; 
	return 0; 
} 
