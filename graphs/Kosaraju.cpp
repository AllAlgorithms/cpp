//this code if for kosaraju algorithm
//the algorithm is used to find strongly connected components in a graph
#include <bits/stdc++.h>
using namespace std;

vector<int> g[100000]; //adjacency list for the graph
vector<int> grev[100000]; //adjacency list for the reversed graph

//printing a vector
void print(vector<int> cc){
	int size = cc.size();
	for(int i = 0 ; i < size ; i++){
		cout << cc[i] << " ";
	}
	cout << endl;
}

//DFS CALLS
void dfs1(int source , stack<int> &order , bool * visited){
	visited[source] = true;
	for(auto i : g[source]){
		if(!visited[i])	dfs1(i , order , visited);
	}
	order.push(source);
}
void dfs2(int source , bool * visited , vector<int> &cc){
	visited[source] = true;
	cc.push_back(source);
	for(auto i : grev[source]){
		if(!visited[i])	dfs2(i , visited , cc);
	}
}

//code for finding and printing SCC(Stongly Connected Components)
void SCC(int n){
	bool * visited = new bool[n]{false};
	stack<int> order;
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]){
			dfs1(i , order , visited);
		}
	}
	delete []visited;
	bool * visited2 = new bool[n]{false};	
	while(!order.empty()){
		int source = order.top();
		order.pop();
		vector<int> cc;
		dfs2(source , visited2 , cc);
		print(cc);
	}
	delete []visited2;	
}


int main(){
	//n is number of vertices
	//m is number of edges
	int n , m , a , b;
	cin >> n >> m; //inputting number of vertices and edges
	//inputting m edges
	for(int i = 0 ; i < m ; i++){
		//a directed edge from a to b
		cin >> a >> b;
		g[a].push_back(b);
		grev[b].push_back(a);
	}
	SCC(n);//call function to find and print SCC
}
