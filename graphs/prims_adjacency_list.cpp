//
// The following is an implementation of Prim's algorithm
// using adjacency list representation of a graph. The data structure
// min heap is used for this. There are, again, two implementations
// in this, the min heap code can be written differently in a class, or
// the priority_queue present in STL can be used. Here, it's the
// latter.
// Now, a priority_queue is essentially a max heap, but can be used
// as given below to form a min heap. The loop statements execute
// v+e times, in addition to log(v) time for adding to priority_queue.
// Overall, O(v+e)*O(log(v)) = O((e+v)*log(v))
// e = O(v^2) for dense graphs, because e <= v*(v-1)/2 for any connected graph.
// And e = O(v), or, v = O(e) for sparsely connected graphs.
// Hence, O((e+v)*log(v)) = O(e*log(v)).
// The pop() and top() operations take O(log(v)) and O(1) time
// respectively.
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/graphs/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Pritam Negi
// Github: @pritamnegi
//

#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

int main(){

    cout << "Enter number of vertices of the graph" << endl;
    int v;
    cin >> v;

    vector<pair<int, int> > adj[v];
    int i, j; //Iterators

    cout << "Enter number of edges of the graph" << endl;
    int e;
    cin>>e;

    cout << "Enter the vertices and their edge weights in the following format :" << endl;
    cout << "Vertex1 Vertex2 Weight" << endl;
    cout << "PS : First vertex should be 0." << endl;

    for (i = 0; i < e; i ++){
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back(make_pair(w,v2));
        adj[v2].push_back(make_pair(w,v1));
    }

    int mst[v];
    //Array to store MST
    int keys[v];
    //Key values of every edge
    bool included[v];
    //The corresponding vertex has already been included if true

    for (i = 0; i < v; i ++){
        mst[i] = -1;
        keys[i] = INF;
        //Set all key values to infinity
        included[i] = false;
        //None of the vertices have been included yet
    }

    int selected = 0;

    priority_queue< pair<int,int> , vector<pair<int,int> > , greater< pair<int,int> > > Q;
    //Priority queue as a minHeap
    pair<int,int> p;
    //This is used to traverse through the vertices

    mst[0] = 0;
    Q.push(make_pair(0,0));
    //To start MST with node 0, the root node

    while(!Q.empty()){

        p = Q.top();
        selected = p.second;
        //Edge with minimum weight is selected
        Q.pop();

        for(int i = 0;i < adj[selected].size(); i++ ){
            int next = adj[selected][i].second;
            //This variable stores index of the adjacent vertices to 'selected'
            int weight = adj[selected][i].first;

            if (!included[next] && keys[next] > weight){
                keys[next] = weight;
                Q.push(adj[selected][i]);
                mst[next] = selected;
            }
        }
    }

    cout << "Minimum spanning tree has been generated." << endl;

    for(i = 1; i < v; i++){
        cout<< mst[i] <<" ";
    }
    return 0;
}
