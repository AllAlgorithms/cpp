#include <iostream>
#include <algorithm>
#include <vector>

const int INF = 2e9 + 10;

void printArray(std :: vector <int> arr){
    std :: cout << '[';
    const int n = arr.size();
    for(int i = 0; i != n; ++ i){
        if(i) std :: cout << ", ";
        std :: cout << arr[i];
    }
    std :: cout << ']';
}

int LIS(std :: vector <int> arr){
    const int n = arr.size() + 1;
    int dp[n];
    dp[0] = -INF;
    for(int i = 1; i < n; ++ i){
        dp[i] = INF;
    }
    int pos = 0;
    for(int i = 0; i != n - 1; ++ i){
        int cur = std :: upper_bound(dp, dp + n, arr[i]) - dp;
        if(dp[cur] > arr[i]) dp[cur] = arr[i];
    }
    for(int i = 0; i != n; ++ i){
        if(dp[i] == INF) break;
        pos = i;
    }
    return pos;
}

int main(){
    std :: vector <int> array = {3, 4, 5, 2, 6, 7};
    std :: cout << "The Longest Increasing sequence of ";
    printArray(array);
    std :: cout << " is " << LIS(array);
    return 0;
}
