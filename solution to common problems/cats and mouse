//https://www.hackerrank.com/challenges/cats-and-a-mouse

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int q;
    int arr[100][3];
    cin>>q;
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<q;i++)
    {
        if(abs(arr[i][0]-arr[i][2])>abs(arr[i][1]-arr[i][2]))
            cout<<"Cat B\n";
        else if(abs(arr[i][0]-arr[i][2])<abs(arr[i][1]-arr[i][2]))
            cout<<"Cat A\n";
        else
            cout<<"Mouse C\n";
    }
    return 0;
}
