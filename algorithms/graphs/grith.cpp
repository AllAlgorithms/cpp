#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const long long MX = 2e5 + 3;
vector<long long> adj[MX];
long long mark[MX], dis[MX], ans;

void DFS(long long u, long long par, long long k);

int32_t main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n, m;
	long long u, v;
	cin >> n >> m;
	ans = m + 1;
	for(long long i=0; i<m; i++)
	{
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for(int i=1; i<n+1; i++)
	{
		dis[i]=0;
		DFS(i, -1, mark[i]);
	}
	if(ans == m+1) 
		cout<<-1;
	else 
		cout<<ans;
	return 0;
}

void DFS(long long u, long long par, long long k)
{
	mark[u]++;
	if(u == par)
	{
		ans = min(ans, (long long)1);
	}
	for(auto v: adj[u])
	{
		if(mark[v] == k)
		{
			dis[v] = dis[u]+1;
			DFS(v, u, k);
		}
		else if(v != par)
		{
			ans = min(ans, dis[u]+dis[v]+1);
		}
	}
}