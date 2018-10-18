/*

	You are given with an array of integers and an integer K. 
	Write a program to find and print all pairs which have difference K.
	
	Sample Input 1 :
	4 
	5 1 2 4
	3
	Sample Output 1 :
	2 5
	1 4
*/


#include<iostream>
using namespace std;


void printPairs(int *input, int n, int k) {
	
  int hash[10000];
  for(int i = 0;i < n;i++)
  {
    	for(int j = i+1; j < n;j++)
        {
          	if((input[i] - input[j]) == k)
              cout << input[j] << " " << input[i] << endl;
          	else if((input[j] - input[i]) == k)
           	cout << input[i] << " " << input[j] << endl;
        }
  }

}


int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}

