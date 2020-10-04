#include <iostream>
#include <stdio.h>
#include <vector>
#include <iterator>
using namespace std;

vector<bool> visited; //this vector will mark visited components
vector<vector<int> > graph; //this will store the graph represented internally as an adjacency list
//this is because the adjacency list representation is the most suited to use DFS procedure on a given graph

int sz_connect_comp = 0; //this will store the size of current connected component (problem-specific feature)

void dfs(int v)
{
	sz_connect_comp++; //"useful feature" performed on this DFS, this can vary from problem to problem
	visited[v] = true;
	
	for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++)
	{
		if(! visited[*it]) //note that *it represents the adjacent vertex itself
		{
			dfs(*it);
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		graph = vector<vector<int> > (n); //initialization of the graph
		for(int i = 0; i < m; i++)
		{
			int u,v;
			cin >> u >> v;
			u--;
			v--;
			//these are added this way due to the friendship relation being mutual
			graph.push_back(v);
			graph[v].push_back(u);
		}
		int res = 0; // the number of fire escape routes
		int ways = 1; // the number of ways to choose drill captains
		visited = vector<bool> (n, 0); // initially mark all vertices as unvisited 
		for(int u = 0; u < n; u++)
		{
			//if the vertex was visited we skip it.
			if(visited==true)
				continue;
			// if vertex was not visited it starts a new component
			res++; // so we increase res
			sz_connect_comp = 0; // init sz_connect_comp
			dfs(u); // and calculate it through the dfs, marking visited vertices
			// we multiply ways by sz_connect_comp modulo 1000000007
			ways = (long long)sz_connect_comp * ways % 1000000007;
		}
		printf("%d %d", res, ways);

	}
	return 0;
}
