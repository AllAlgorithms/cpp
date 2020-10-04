#include <iostream>
using namespace std;
int longestIncreasingSubsequence(int A[],int size){
    int dp[size];
    for(int i=0;i<size;i++) dp[i] = 1;
    for(int i=1;i<size;i++){
        for(int j=0;j<i;j++){
            if(A[j]<A[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int lis = 0;
    for(int i=0;i<size;i++) {
    	lis = max(lis,dp[i]);
    }
    
    return lis;
}
int main() {
	
	int A[] = {1,3,5,9,8};
	cout<<longestIncreasingSubsequence(A,5);
	return 0;
}
