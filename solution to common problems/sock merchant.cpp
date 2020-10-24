//https://www.hackerrank.com/challenges/sock-merchant

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[100],total,count=0;
    cin>>total;
    for(int i=0;i<total;i++)
        cin>>arr[i];
    for(int j=0;j<total;j++)
    {
        L1:
        for(int k=j+1;k<total;k++)
        {
            if(arr[k]==arr[j]&&arr[k]!=0&&arr[j]!=0)
            {
                count++;
                arr[j]=0;
                arr[k]=0;
                j++;
                goto L1;            
            }
        }
    }
    cout<<count;
    return 0;
}