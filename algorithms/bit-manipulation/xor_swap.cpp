#include <iostream>
using namespace std;
int main() 
{
    int a = 1, b = 2;
    cout << "a = " << a << ", b = " << b << endl;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "a = " << a << ", b = " << b << endl;
}