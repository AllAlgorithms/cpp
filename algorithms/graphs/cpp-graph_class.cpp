/**Author : Vivek Bhardwaj
 * Contributed to : https://github.com/AllAlgorithms/cpp
 **/

#include<bits/stdc++.h>
using namespace std;

class graph{
    private : 
        vector<vector<int>> adj;
        vector<vector<long long>> weight_matrix;
        vector<bool> visited;
        vector<long long> distance;
        vector<pair<int,int>> edge_list;
        long long ** weight;
        const long long INF=1e18;
        

        void visited_util(){
            fill(visited.begin(),visited.end(),false); 
        }

        void dfs_util(int start){
            visited[start]=true;
            //do something ......
            cout<<start<<" ";
            for(auto i : adj[start]){
                if(!visited[i])
                dfs_util(i);
            }
        }

        void bfs_util(int start){
            queue<int> q; q.push(start); visited[start]=true;
            //do something ......
            //cout<<start<<" ";
            while(!q.empty()){             
                for(auto i : adj[q.front()]){
                    if(!visited[i]){
                        //do something ......
                        //cout<<i<<" ";
                        visited[i]=true;
                        q.push(i);
                    }
                }
                q.pop();
            }
        }

        void dijkstra_util(int start){
            int min_distance_vertex=-1;
            for(int x=0;x<adj.size();x++){
                long long min_distance=INF;
                for(int j=0;j<distance.size();j++){
                    if(distance[j]!=INF&&distance[j]<min_distance&&visited[j]==false) {
                        min_distance=distance[j];
                        min_distance_vertex=j;
                    }
                }

                visited[min_distance_vertex]=true;
                for(auto i : adj[min_distance_vertex]){
                    
                    if(!visited[i]){
                        distance[i]= min (distance[i],min_distance+weight[min_distance_vertex][i]);
                    }
                }
            }
            //do something....
            for(auto i : distance) cout<<i<<" ";
        }

        void bellman_ford_util(int start){
            for(int i=0;i<vertices-1;i++){
                for(auto it  : edge_list){
                    if(distance[it.first]!=INF)
                    distance[it.second]=min(distance[it.second],distance[it.first]+weight[it.first][it.second]);
                }
            }
            //do something....
            for(auto i  : distance) cout<<i<<" ";

            for(auto it : edge_list){
                if(distance[it.second]!=min(distance[it.second],distance[it.first]+weight[it.first][it.second])){
                    cout<<"Graph has a negative weight cycle "<<"\n";break;
                }
            }
        }

    
    public : 
        int vertices;
        graph(int vertex){
            adj.resize(vertex);
            visited.resize(vertex);
            distance.resize(vertex);
            weight_matrix.resize(vertex);
            weight =new long long*[vertex];
            for(int i=0;i<vertex;i++){
                weight[i]=new long long[vertex];
            }
            for(int i=0;i<vertex;i++){
                for(int j=0;j<vertex;j++){
                    if(i!=j)weight[i][j]=INF;
                    else weight[i][j]=0;
                }
            }
            this->vertices=vertex;
        }

        void add_directed_edge(int from,int to){
            adj[from].push_back(to);
            edge_list.emplace_back(from,to);
        }

        void add_directed_edge(int from,int to,int weigh){
            adj[from].push_back(to);
            weight[from][to]=weigh;
            edge_list.emplace_back(from,to);
        }

        void add_undirected_edge(int x,int y,int weigh=1){
            adj[x].push_back(y);
            adj[y].push_back(x);
            edge_list.emplace_back(x,y);
            edge_list.emplace_back(y,x);
            weight[x][y]=weigh;
            weight[y][x]=weigh;
        }

        void bfs(int start){
            visited_util();
            bfs_util(start);          
        }

        void dfs(int start){
            visited_util();
            dfs_util(start);
        }

        void dijkstra(int start){
            visited_util();
            fill(distance.begin(),distance.end(),INF);
            distance[start]=0;
            dijkstra_util(start);
        }

        void bellman_ford(int start){
            visited_util();
            fill(distance.begin(),distance.end(),INF);
            distance[start]=0;
            bellman_ford_util(start);
        }

        void floyd_warshell(){

            for(int i=0;i<vertices;i++)
                for(int j=0;j<vertices;j++)
                    weight_matrix[i].push_back(weight[i][j]);

            //source
            for(int i=0;i<vertices;i++){
                //via
                for(int j=0;j<vertices;j++){
                    //to
                    for(int k=0;k<vertices;k++){
                        weight_matrix[i][k]=min(weight_matrix[i][k],weight_matrix[i][j]+weight_matrix[j][k]);
                    }            
                }
            }
            
            for(int i=0;i<vertices;i++){
                for(int j=0;j<vertices;j++){
                    cout<<weight_matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){

    graph g(5);
    g.add_undirected_edge(0,1,4);
    g.add_undirected_edge(0,2,2);
    g.add_undirected_edge(1,2,2);
    g.add_undirected_edge(1,3,5);
    g.add_undirected_edge(2,3,5);
    g.add_undirected_edge(2,4,9);
    g.add_undirected_edge(3,4,4);
    //g.dfs(0);
    //g.bfs(0);
    for(int i=0;i<g.vertices;i++){
        //g.dijkstra(i); cout<<endl;
    }
    g.floyd_warshell();
    
}
