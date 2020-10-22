//
// The following is C++ implementation of Kruskal's algorithm
//  on a graph.  

// Kruskal's Algorithm is used to find the minimum spanning tree
// of a graph.
// Here 'Disjoint Sets' method is used for cycle detection.
// Disjoint sets are sets whose intersection is empty set 
// if they don't have any common element 

// The All ▲lgorithms Project
//
// https://allalgorithms.com/graphs/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Himanshu Airan
// Github: @Himanshu-77
//


#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 1e4 + 5;
int id[MAX] ;


int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

int main()
{
    int nodes, edges, x, y, weight;
    int cost, minimumCost=0;
    pair<int, pair<int, int> > graph[MAX];

    // initially all elements are in different sets
    for(int i = 0; i<MAX; ++i)
        id[i] = i;


    // input number of nodes and edges in graph
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        graph[i] = make_pair(weight, make_pair(x, y));
    }

    // Sort the edges in the ascending order of weights
    sort(graph, graph + edges);

    // find weight of minimum spanning tree
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = graph[i].second.first;
        y = graph[i].second.second;
        cost = graph[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;

            // join sets of both elements
            id[root(x)] = id[root(y)];
        }    
    }


    cout << "Cost of minimum spanning tree is : "
         << minimumCost << endl;
    return 0;
}
