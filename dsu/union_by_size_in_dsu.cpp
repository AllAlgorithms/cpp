#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
const int MAX_SIZE = 1e5+7; //It can be increased to maximum global size available
int parent[MAX_SIZE];
int size_v[MAX_SIZE];

void make_set(int val)
{
    parent[val] = val;
    size_v[val] = 1;
}
int find_parent_path_compression(int val)
{
    if(val == parent[val])
    {
        return val;
    }
    return parent[val] = find_parent_path_compression(parent[val]);
}

void union_set(int x, int y)
{
    x = find_parent_path_compression(x);
    y = find_parent_path_compression(y);
    if(x != y)
    {
        if(size_v[x]<size_v[y])
        {
            swap(x,y);
        }
        parent[y] = x;
        size_v[x] += size_v[y];
    }
}

int main()
{
    int n = 5;
    int elements[n];
    for(int i=0;i<n;i++)
    {
        elements[i] = 2*i+1;
        make_set(elements[i]);
    }
    union_set(elements[2], elements[4]);
    union_set(elements[1], elements[4]);
    if (find_parent_path_compression(elements[2]) != find_parent_path_compression(elements[1]))
    {
        cout<<"The union set method failed!! \n";
    }
    else
    {
        cout<<"The union set method is working fine \n";
    }
    //The output of this is "The union set method is working fine"
    //And hence the code is correct
    return 0;
} 