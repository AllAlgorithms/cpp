//
// Count disconnected components implementation in C++
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/graphs
// https://github.com/allalgorithms/cpp
//
// Contributed by: Rituparno Biswas
// Github: @roopbiswas
//
#include<iostream>
#include<list>
using namespace std;

int count=1;
// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
    for (int i = 0; i < V; i++)
        if(visited[i] == false)
        {
            count++;
            DFSUtil(i, visited);
        }
}

int main()
{
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(4, 5);
    g.addEdge(6, 7);
    g.addEdge(6, 8);

    g.DFS(2);
    cout << "Number of disconnected components in the given graph is : " <<count;;

    return 0;
}
