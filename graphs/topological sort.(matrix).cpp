#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v,adj[100][100],st[100],top;
public:
     void read()
        {
            int i,j;

            cout<<"vertex"<<endl;
            cin>>v;
            for(i=0;i<v;i++)
            {
                for(j=0;j<v;j++)
                {
                    cin>>adj[i][j];
                   // adj[j][i]=adj[i][j];
                }
            }
        }
        void topo(int u,int vis[])
        {
            vis[u]=1;
            int i;
            for(i=0;i<v;i++)
            {
                if(adj[u][i]==1&&vis[i]==0)
                    topo(i,vis);

            }
            top++;
            st[top]=u;
        }
    void toposort()
    {
        int i,vis[v];
        top=-1;
        for(i=0;i<v;i++)
            vis[i]=0;
        for(i=0;i<v;i++)
        {

            if(vis[i]==0)
                topo(i,vis);
        }
        while(top>=0)
        {
            cout<<st[top]<<" ";
            top--;
        }
        cout<<endl;
    }

};
int main()
{
    graph g;
    g.read();
    g.toposort();
}
