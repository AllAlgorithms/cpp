#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int counter = 0;

int binarySearch(vector<int> &arr, unsigned int low, unsigned int high, int num){

	if(low > high)
		return -1;
	else
	{
		int mid = (low + high) / 2;
		counter++;

		if(arr[mid] == num)
			return mid;
		else if(arr[mid] < num)
			return binarySearch(arr, mid + 1, high, num);
		else
			return binarySearch(arr, low, mid-1, num);
		}
}

string toString (int number){
	stringstream stream;
        stream << number;
        return stream.str() ;
}

int main(int argc, char* argv[]){
	int x = 0;
	vector<int> arr;
	int result;
	string line, line2;
	fstream file;
	ifstream infile(argv[1]);
	file.open(argv[2], ios::out);
	
	if (!infile.is_open()) {
		cout<<"File doesn't exist!";
	}

	getline(infile, line);
	stringstream buffer(line);

	while(buffer >> x){
		arr.push_back(x);

		if(buffer.peek() == ',') // >> std::ws)
			buffer.ignore();
	}
	sort(arr.begin(), arr.end());
	int y = 0;
	while(infile >> y)
	{
		counter = 0;
		result = binarySearch(arr, 0, arr.size() - 1, y);
		(result == -1) ? file << toString(y) + " not found" << endl : file<<toString(y) + " found at position " << result+1 <<" after " << counter << " comparisons"<<endl;
	}
}
