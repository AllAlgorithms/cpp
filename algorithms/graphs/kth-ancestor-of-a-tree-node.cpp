//Kth Ancestor of a treenode using Binary Lifting. If kth ancestor does not exist, return -1. Implemented in C++17
// author : github.com/yadavnaman
#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
    
public:
    vector< vector<int> >dp; // dp[i][node] : node's 2^i parent
    int n;
    TreeAncestor(int m, vector<int>& parent) {
        n = m;
        dp.resize(20,vector<int> (m,-1));
        for(int node = 0 ; node < parent.size(); ++node){
            dp[0][node] = parent[node];
        }
        // 2^i parent
        for(int i = 1; i< 20; ++i) {
            for(int node = 0 ; node < parent.size(); ++node) {
                int node_par = dp[i-1][node];
                if(node_par != -1){
                    dp[i][node] = dp[i-1][node_par];
                }
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 20; ++i) {
            if(k & (1<<i)) {
                node = dp[i][node];
                if(node == -1){
                    return -1;
                }
            }
        }
        return node;
    }
};

int main() {
    int m,k,node;
    cin >> m >> k;
    vector<int> par(m);
    for(int i = 0; i < m; ++i){
        cin>>par[i];
    }
    cin >> node;
    TreeAncestor* obj = new TreeAncestor(m,par);
    cout << obj->getKthAncestor(node,k) <<"\n";
}