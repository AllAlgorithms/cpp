#include<iostream>
using namespace std;
int comb(int n, int k){
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0 || j==i){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[n][k];
}

//Space Optimized Solution
int comb(int n, int k){
    int dp[k+1];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=min(i,k);j>0;j--){
            dp[j] = dp[j]+dp[j-1];
        }
    }
    return dp[k];
}
int main(){
    int n=4,k=2;
    cout<<comb(n,k)<<endl;
}