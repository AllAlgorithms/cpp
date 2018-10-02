//cycle detection in graph implemented in C++
//Author : Rituparno Biswas


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int check=0;
int visited[1000]={0};
vector<int > v[1000];

void dfs(int curr , int p)
{
	visited[curr]=1;
	for(auto i:v[curr])
	{
		if(visited[i]==1)
		{
			if(i!=p)
				check=1;
		}
		else
		{
			dfs(i, curr);
		}
	}
}


void addEdge(int a, int b) 
{ 
    v[a].push_back(b); // Add w to v’s list. 
    v[b].push_back(a); // Add v to w’s list. 
} 

int main() 
{ 
	addEdge(1, 0); 
    addEdge(0, 2);  
    addEdge(1, 2); 
    addEdge(0, 3); 
    addEdge(3, 4); 
    dfs(0,-1);
    if(check)
    	cout<<"Cycle present";
    else
    	cout<<"Cycle not present";
	return 0; 
} 