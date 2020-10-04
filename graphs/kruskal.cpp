// The All ▲lgorithms Project
//
// https://allalgorithms.com/graphs/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Leonardo Su
// Github: @Leonardosu

#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

const int N = 100010;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> edges;

int p[N],lv[N];
int total_cost = 0,n,m;

//Union-Find
//-------
int find(int x)
{
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

void join(int x,int y)
{
	x = find(x);
	y = find(y);

	if(x == y) return;
	if(lv[x] < lv[y]) p[x] = y;
	else if(lv[x] > lv[y]) p[y] = x;
	else
	{
		p[x] = y;
		lv[y]++;
	}	
}
//-------


int main()
{

	cin>>n>>m; // "n" is the  number of vertex and "m" = number of edges

	for(int i=1;i<=n;++i)
		p[i] = i,lv[i] = 0;

	int a,b,c;
	for(int i=1;i<=m;++i) // Read the input, there is an edge between "a" and "b" with cost c
	{
		cin>>a>>b>>c;
		edges.pb(mp(c,mp(a,b) ));
	}

	// Kruskal 
	// --------
	sort(edges.begin(),edges.end());

	for(int i=0;i<edges.size();++i)
	{
		int a = edges[i].s.f;
		int b = edges[i].s.s;
		if(find(a) != find(b))
		{
			join(a,b);
			total_cost+=edges[i].f;
		}
	}
	// --------
	cout<<total_cost<<"\n";
}
