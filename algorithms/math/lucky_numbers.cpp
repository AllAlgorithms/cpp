//
// Lucky Numbers Implementation in C++
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/math
// https://github.com/allalgorithms/cpp
//
// Contributed by: Sathwik Matsa
// Github: @sathwikmatsa
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// returns a vector of int containing lucky numbers in range [1,n]
vector <int> lucky_numbers(int n){

	vector <int> seive;

	// store numbers from 1 to n in the vector
	for(int i = 1; i<=n; i++){
		seive.push_back(i);
	}

	int survivor = 1;
	int delete_every = 2;
	int index;
	while(seive.size() >= delete_every){
		index = delete_every-1;
		while(index < seive.size()){
			seive.erase(seive.begin()+index);
			index+=(delete_every-1);
		}
		delete_every = survivor = (*(++find(seive.begin(), seive.end(), survivor)));
	}

	return seive;
}

int main(){
	int n;
	cout << "Enter a number: ";
	cin>>n;
	vector <int> luckyNumbers = lucky_numbers(n);
	cout << "lucky numbers up to " << n << ":" <<endl;
	for ( vector<int>::iterator it = luckyNumbers.begin() ; it < luckyNumbers.end(); it++ ){
		cout << *it << " ";
	}
	cout<<endl;
	return 0;
}
