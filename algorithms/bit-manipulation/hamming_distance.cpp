#include <iostream>
using namespace std;

unsigned int bitCount(unsigned int value) {
    unsigned int count = 0;
    while (value) {         // until all bits are zero
        if (value & 1)      // check lower bit
            count++;
        value >>= 1;        // shift bits, removing lower bit
    }
    return count;
}

int hamming_distance(int a, int b) {
    if (a<0 || b<0)
        throw "Both arguments must be >=0 for finding hamming distance.";
    return bitCount(a^b);
}

int main() {
    int a = 11; // 1011 in binary
    int b = 2;  // 0010 in binary

    cout << "Hamming distance between " << a <<" and " << b 
    <<" is " << hamming_distance(a, b) << endl;
}