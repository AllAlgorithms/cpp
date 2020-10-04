#include<bits/stdc++.h>
using namespace std;
void print(vector < list <int> > adjlist,int i,bool vis[])
{   //print strongly connected components
    vis[i]=true;
    cout<<i<<"--> ";
    list<int>::iterator it;
    for(it=adjlist[i].begin();it!=adjlist[i].end();it++)
    {
        if(!vis[*it])
            print(adjlist,*it,vis);
    }
    cout<<endl;

}
stack <int> fillstack(vector < list <int> > adjlist,int i, stack <int> order,bool vis[])
{
    vis[i]=true;
    list<int>::iterator it;
    for(it=adjlist[i].begin();it!=adjlist[i].end();it++)
    {
        if(vis[*it]==false)
            fillstack(adjlist,*it,order,vis);
    }
    order.push(i);
   //cout<<order.top()<<" ";
 return order;
}
int kosaraju( vector < list <int> > adjlist, int v)
{   int count=0;
    bool vis[v];
    int i;
    //mark all nodes as unvisited
    for(i=0;i<=v;i++)
        vis[i]=false;
    stack <int> order;
    list<int>::iterator it;
    for(i=1;i<=v;i++)
    {
        if(vis[i]==false)
            //fill stack in order of finish times using DFS
            order = fillstack(adjlist,i,order,vis);
    }
   /*while(!order.empty())
    {
        cout<<order.top()<<" ";
        order.pop();
    }*/
    for(i=1;i<=v;i++)
        vis[i]=false;

    for(i=0;i<v;i++)
    {   //reverse the graph
        for(it=adjlist[i].begin();it!=adjlist[i].end();it++)
            adjlist[*it].push_back(i);
    }
    while(order.empty()==false)
    {   //check connectivity by performing DFS on reverse graph
        i= order.top();
        order.pop();
        if(vis[i]==false)
            {//print(adjlist,i,vis);
                count++;
            }

    }
    return count;
}
int main()
{
    int v,e,v1,v2,i;
    cin>>v>>e;
    vector < list <int> > adjlist(v+1);
    for(i=0;i<e;i++)
    {
        cin>>v1>>v2;
        adjlist[v1].push_back(v2);
        adjlist[v2].push_back(v1); //for undirected graph
    }

    int ans=kosaraju(adjlist,v);
    cout<<ans<<endl;
}
