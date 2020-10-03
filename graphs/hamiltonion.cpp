#include<iostream>
#include<vector>
#include<string>
#include<climits>

using namespace std;

class Edge {
    public: 
        int nbr;
        int wt;
};
vector<vector<Edge>> graph;

void addEdge(int v1, int v2, int wt)
{
    Edge e1;
    e1.nbr = v2;
    e1.wt = wt;
    graph[v1].push_back(e1);

    Edge e2;
    e2.nbr = v1;
    e2.wt = wt;
    graph[v2].push_back(e2);
}

void display()
{
    for(int v = 0; v < graph.size(); v++)
    {
        cout << v << " -> ";
        for(int n = 0; n < graph[v].size(); n++)
        {
            Edge ne = graph[v][n];
            cout << "[" << ne.nbr << "-" << ne.wt << "], ";
        }
        cout << "." << endl;
    }
}

bool haspath(int s, int d, vector<bool>& visited)
{
    if(s == d)
    {
        return true;
    }

    visited[s] = true;
    for(int n = 0; n < graph[s].size(); n++)
    {
        Edge ne = graph[s][n];
        if(visited[ne.nbr] == false)
        {
            bool hpfntod = haspath(ne.nbr, d, visited);
            if(hpfntod == true)
            {
                return true;
            }
        }
    }

    return false;
}

void printallpaths(int s, int d, vector<bool>& visited,
                   string psf, int dsf)
{
    if(s == d)
    {
        cout << psf << d << "@" << dsf << endl;
        return;
    }
    visited[s] = true;
    for(int n = 0; n < graph[s].size(); n++)
    {
        Edge ne = graph[s][n];
        if(visited[ne.nbr] == false)
        {
            printallpaths(ne.nbr, d, visited, 
                          psf + to_string(s), 
                          dsf + ne.wt);
        }
    }
    visited[s] = false;
}
void hamiltonian(int s, vector<bool>& visited, string asf, int os)
{
    if(csf == graph.size()-1)
    cout<<asf<<s;
    for(int n = 0; n < graph[s].size(); n++)
    {
        Edge ne = graph[s][n];
        if(visited[ne.nbr] == false)
        {
            hamiltonian()
        }
    }
}
{
    psf += to_string(s);
    cout<<psf;
    for(int n = 0; n < graph[s].size(); n++)
    {
        Edge ne = graph[s][n];
        if(ne.nbr == os)
        {
            cout<<"*"<<endl;
            return;
        }
    }
    cout<<"."<<endl;
    return;
}
int main(int argc, char** argv)
{
    graph.push_back(vector<Edge>()); // 0
    graph.push_back(vector<Edge>()); // 1
    graph.push_back(vector<Edge>()); // 2
    graph.push_back(vector<Edge>()); // 3
    graph.push_back(vector<Edge>()); // 4
    graph.push_back(vector<Edge>()); // 5
    graph.push_back(vector<Edge>()); // 6

    addEdge(0, 1, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 10);
    addEdge(0, 3, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 3);
    addEdge(5, 6, 3);
    addEdge(4, 6, 8);

    display();
    vector<bool> visited (7, false);
    // cout << haspath(0, 6, visited) << endl;
    printallpaths(0, 6, visited, "", 0);
}