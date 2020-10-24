
//https://www.hackerrank.com/challenges/between-two-sets/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m,count=0,flag=0;
    int arr1[10],arr2[10];
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];  
    }
    int max=arr1[0];
    int min=arr2[0];
    for(int i=0;i<n;i++)
    {
        if(arr1[i]>max)
            max=arr1[i];
    }
    for(int i=0;i<m;i++)    
    {
        if(arr2[i]<min)
            min=arr2[i];
    } 
    for(int i=max;i<=min;i++)
    {   
        flag=0;
        for(int j=0;j<n;j++)
        {
            if(i%arr1[j]!=0)
            {   
                flag=1;
                    
            }
        }
        for(int j=0;j<m;j++)
        {
            if(arr2[j]%i!=0)
            {
                flag=1;
                
            }
        }
        if(flag==0)
        {
            count++;      
        }
    }
    cout<<count;   
    return 0;
}
