//
// C++ program to demonstrate Factorial Algorithm
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/math
// https://github.com/allalgorithms/cpp
//
// Contributed by: Pablo Trinidad
// Github: @pablotrinidad
//

#include <iostream>
using namespace std;

/*
    @author Roman Korostenskyi
    @date 08.10.2018

    Simple factorial algorithm based on loop
*/
int factorial_loop(int n) {
    int output = 1;

    for (int i = n; i >= 1; i--) {
        output *= i;
    }

    return output;
}

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
