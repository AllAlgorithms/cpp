#include <iostream>

int fibonacci_fast(int n) {
    // write your code here
    if ( n == 0 ) {
        return 0;
    }
    int fin[3];
    fin[0]=0;
    fin[1]=1;
    for (int i = 2; i <= n; i++) {
    	fin[2] = fin[0] + fin[1];
        fin[0] = fin[1];
        fin[1] = fin[2];
    }
    return fin[1];
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
/*
Space Optimization for Fibonacci Number
Space Complexity - O(1)
Time Complexity - O(n)
*/
