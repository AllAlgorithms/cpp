#include <iostream>
#include <algorithm>

const int INF = 2e9 + 10;

int arraySize(int arr[]){
    return 6;
}

void printArray(int arr[]){
    std :: cout << '[';
    const int n = arraySize(arr);
    for(int i = 0; i != n; ++ i){
        if(i) std :: cout << ", ";
        std :: cout << arr[i];
    }
    std :: cout << ']';
}

int LIS(int arr[]){
    const int n = arraySize(arr) + 1;
    int dp[n];
    dp[0] = -INF;
    for(int i = 1; i != n; ++ i){
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
    int array[6] = {3, 4, 5, 2, 6, 7};
    std :: cout << "The Longest Increasing sequence of ";
    printArray(array);
    std :: cout << " is " << LIS(array);
    return 0;
}
