// C++ program to divide a string 
// in n equal parts 
#include<iostream> 
#include<string.h> 

using namespace std; 

class string_division
{ 

// Function to print n equal parts of str 
public: 
void divide_String(char str[], int n) 
{ 
	
	int str_size = strlen(str); 
	int i; 
	int part_size; 

	// Check if string can be divided in 
	// n equal parts 
	if (str_size % n != 0) 
	{ 
		cout<<"Invalid Input: String size"; 
		cout<<" is not divisible by n"; 
		return; 
	} 

	// Calculate the size of parts to 
	// find the division points 
	part_size = str_size / n; 
	for (i = 0; i< str_size; i++) 
	{ 
		if (i % part_size == 0) 
			cout<<endl; 
		cout<< str[i]; 
	} 
} 
}; 

// Driver code 
int main() 
{ 
	string_division g; 
	
	// length od string is 28 
	char str[] = "a_simple_divide_string_quest"; 

	// Print 4 equal parts of the string 
	g.divide_String(str, 4); 
	return 0; 
} 

