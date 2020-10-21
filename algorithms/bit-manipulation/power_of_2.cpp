#include <iostream>
#include <vector>
using namespace std;

bool ispower2(int x) {
    return x>0 && (x & (x-1))==0;
}

int main() {
    vector<int> arr{1, 2, 3, 4, 8, 10};
    for(int x : arr){
        cout << x << " is " << (ispower2(x) ? "" : "not ") << "a power of 2." 
        << endl;
    }
}