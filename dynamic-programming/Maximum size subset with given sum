#include<bits/stdc++.h> 
using namespace std; 
  
    int isSubsetSum(int set[], int n, int sum)  
    {   
        bool subset[sum + 1][n + 1];  
        int count[sum + 1][n + 1];  
  
        for (int i = 0; i <= n; i++)  
        {  
            subset[0][i] = true;  
            count[0][i] = 0;  
        }  
    
        for (int i = 1; i <= sum; i++)  
        {  
            subset[i][0] = false;  
            count[i][0] = -1;  
        }  
  
        for (int i = 1; i <= sum; i++)  
        {  
            for (int j = 1; j <= n; j++)  
            {  
                subset[i][j] = subset[i][j - 1];  
                count[i][j] = count[i][j - 1];  
                if (i >= set[j - 1])  
                {  
                    subset[i][j] = subset[i][j] ||  
                                subset[i - set[j - 1]][j - 1];  
  
                    if (subset[i][j])  
                        count[i][j] = max(count[i][j - 1],  
                                    count[i - set[j - 1]][j - 1] + 1);  
                }  
            }  
        }  
  
        return count[sum][n];  
    }  
  
int main() 
{ 
    int set[] = { 2, 3, 5, 10 };  
    int sum = 20;  
    int n = 4;  
    cout<< isSubsetSum(set, n, sum);  
} 
