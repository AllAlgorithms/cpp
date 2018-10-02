// Standard headers and namespace
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
    Given m number of coin types, each of infinite quantity, 
    we need to determine the number of ways that we can create change for n amount.
*/

int main()
{   
    // Take input as n = amount to be changed
    //               m = number of coin types
    int n,m;
    cin>>n>>m;
    // vector to store types of coins
    vector<ll> coins;

    // take input in coins
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        coins.push_back(temp);
    }
    // sort the coins in descending order
    sort(coins.rbegin(), coins.rend());

    // 2-D array for storing overlapping subproblems in dp algorithm
    vector< vector<ll> > v(m, vector<ll> (n+1,0));
    for(int i=0;i<m;i++){
        v[i][0] = 1;
    }

    /* v[i][j] represents the number of ways j amount can be changed using only
     * coin types coins[1..i]
     * Initially, for 0 amount, can be changed in one way for all types of coins. 
     * Further, for each additional type of coin (let value = newC) added, we can change it in all of 
     * previous type combinations as well as add one coin of the new type to combinations
     * of v[i][j-newC].
     */
    for(int i=0;i<m;i++){
        for(int j=1;j<n+1;j++){
            for(int k=i;k>=0;k--){
                if(j>=coins[i-k]){
                    v[i][j]+= v[i-k][j-coins[i-k]];
                }
            }
        }
    }
    // required answer is changing n amount using coins[1..m-1]
    cout<<v[m-1][n]<<endl;
    return 0;
}