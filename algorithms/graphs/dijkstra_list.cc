#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
#define INF 999999

typedef pair<int, int> pii;

list<pii> adj[INF];
int V; 
vector<int> previous(INF, -1);
int dijkstra(int src, int dest) {
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	
	vector<int> dist(INF, INF);
	previous.resize(V);
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for(auto const& i : adj[u]) {
			int v = i.first;
			int w = i.second;

			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
				previous[v] = u;
			}
		}
	}

	return dist[dest];
}

void dijShortPath(int v, list<int>& path) {
/* example:
v = 6;
v = previous[6] (5)
v = previous[5] (2)
...
*/
	for(; v != -1; v = previous[v])
		path.push_front(v);
}

int main() {
/*
nVertex nEdges
sorg dest
ver1 ver2 weight
...
*/
	cin >> V;
	int e, sorg, dest;
	cin >> e >> sorg >> dest;
	int u, v, w;
	for(int i = 0; i < e; i++) {
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	cout << dijkstra(sorg, dest) << endl;
	list<int> path;
	dijShortPath(dest, path);
	for(auto const& i : path)
		cout << i << ' ';

	return 0;
}
