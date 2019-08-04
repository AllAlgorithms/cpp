#include<bits/stdc++.h>

using namespace std;


typedef vector<int> vi;
typedef pair<int,int> pi;

#define int long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(int i =a;i < b; i++)

const int MX = 2e5 + 3;
vi adj[MX];
int mark[MX],dis[MX], ans;

void DFS(int u, int par, int k);

int32_t main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m;
	int u, v;
	cin>>n>>m;
	ans = m + 1;
	REP(i, 0, m)
	{
		cin>>u>>v;
		adj[v].PB(u);
		adj[u].PB(v);
	}
	REP(i, 1, n+1)
	{
		dis[i]=0;
		DFS(i, -1, mark[i]);
	}
	if(ans == m+1) cout<<-1;
	else cout<<ans;
	return 0;
}

void DFS(int u, int par, int k)
{
	mark[u] ++;
	if(u == par)
	{
		ans = min(ans, (int)1);
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