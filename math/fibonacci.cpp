#include <iostream>   //to get the input and print the output
#include <stdint.h>

using std::cin;
using std::cout;

//returns fibonacci number for specified position
int64_t getFibonnaci(unsigned int input){
	//base case
	if (input <= 1){
		return input;
	}
	
	//recursively calls getFibonnaci function to get the previous fibonacci numbers until base case is reached
	//all the previous fibonacci numbers are then added
	//and returns the fibonacci number for current position
	return getFibonnaci(input-1) + getFibonnaci(input-2);
}


int main(){
	int userInput;
	
	//gets user Input
	cout << "Enter a number : \n";
	cin >> userInput;
	
	cout << "The fibonacci number for the sepcified position is: ";
	cout << getFibonnaci(userInput);
	
	return 0;
}