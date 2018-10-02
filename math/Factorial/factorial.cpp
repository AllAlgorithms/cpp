/* Factorial

Author: Pablo Trinidad <github.com/pablotrinidad>
*/

#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if (n <= 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    cout << "Enter an integer n to compute its factorial: ";
    cin >> n;
    int r = factorial(n);
    cout << n << "! = " << r << endl;
    return 0;
}
