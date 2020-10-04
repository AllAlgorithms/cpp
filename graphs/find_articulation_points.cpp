//this code can be used to find Articulation points in a Graph
#include <bits/stdc++.h>
using namespace std;

int timee;// a variable to keep track of the time at which a particular vertex is encounterd

vector<int> graph[100];//adjacency list for the graph (100 is the max number of vertices.. you can change as per your needs)
bool visited[100] , AP[100];
//visited - bool array used in DFS to know whether the node is visited or not
//AP - bool array to tell whether ith vertex is a AP or NOT

int disc[100] , low[100] , parent[100];
//disc - discovery time of a vertex
//low - exit time of a source
//parent - array to tell the parent of ith vertex

//finding all APs
void printAP2(int source){
	visited[source] = true;
	disc[source] = timee++;
	low[source] = disc[source];
	int child = 0;
	for(auto i : graph[source]){
		if(!visited[i]){
			child++;
			parent[i] = source;
			printAP2(i);
			low[source] = min(low[i] , low[source]);
			
			if(parent[source] == source){
				if(child > 1)	AP[source] = true;
			}
			else{
				if(low[i] >= disc[source])	AP[source] = true; // IMP
			}
		}
		else if(i != parent[source])	low[source] = min(low[i] , low[source]);
	}
}

//find and print all APs
void printAP(int n , int source){
	for(int i = 0 ; i < n ; i++)	low[i] = INT_MAX;
	parent[source] = source; //initializing source os source vertex to itself
	printAP2(source);
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]){
			parent[i] = i;
			printAP2(i);
		}	
	}
	for(int i = 0 ; i < n ; i++){
		if(AP[i])	cout << i << " ";
	}
	cout << endl;
}

int main(){
	//n - no. of vertices , e - no. of edges
	int n , e , u , v;
	cin >> n >> e;
	//inputting e edges
	for(int i = 0 ; i < e ; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	printAP(n , 0);
}
