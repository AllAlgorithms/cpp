#include <iostream>
int fibonacci_fast(int n) {
    // write your code here
    int fin[n];
    fin[0]=0;
    fin[1]=1;
    for (int i=2;i<=n;i++)
    	fin[i]=fin[i-1]+fin[i-2];

    return fin[n];
}
int main() {
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
