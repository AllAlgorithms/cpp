#include <iostream>   //to get the input and print the output
#include <stdint.h>

using std::cin;
using std::cout;

int64_t getFibonnaci(unsigned int input){
	if (input <= 1){
		return input;
	}
	
	return getFibonnaci(input-1) + getFibonnaci(input-2);
}


int main(){
	int userInput;
	
	cout << "Enter a number : \n";
	cin >> userInput;
	
	cout << "The fibonacci number for the sepcified position is: ";
	cout << getFibonnaci(userInput);
	
	return 0;
}