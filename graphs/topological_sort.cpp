#include<iostream>
#include<stack>
#include<vector>
#include<stdio.h>
using namespace std;
stack<int> pile;
vector<int> adj[1000];
void dfs(int cur,int vis[])
{
	int i=0;
	for(i=0;i<adj[cur].size();i++)
	{
		if(vis[adj[cur][i]]==0)
		{
			dfs(adj[cur][i],vis);
			vis[adj[cur][i]]=1;
		}
	}
	pile.push(cur);
}
int main()
{
	int e,u,v,n,i;
	int vis[1000]={0};
	cin>>n>>e;
	for(i=0;i<e;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
			dfs(i,vis);
	}
	while(!pile.empty())
	{
		cout<<pile.top();
		pile.pop();
	}
}
