#include<bits/stdc++.h>
using namespace std;
class graph
{
     int v,adj[100][100];
public:
     void read()
        {
            int i,j,e,v1,v2,c;

            cout<<"vertex,edges"<<endl;
            cin>>v>>e;
            for(i=0;i<v;i++)
            {
                for(j=0;j<v;j++)
                {
                    adj[i][j]=999;

                }
            }

            for(i=0;i<e;i++)
            {   cout<<"Enter edge, cost"<<endl;
                cin>>v1>>v2>>c;
                adj[v1][v2]=adj[v2][v1]=c;
            }
            return;
        }
        int find(int v,int p[])
        {
            while(p[v]!=v)
                v=p[v];
            return v;
        }
        void unionij(int i,int j,int p[])
        {
            if(i<j)
                p[j]=i;
            else
                p[i]=j;
        }
        void kruskal()
        {
            int i,j,t[100][2],k=0,min,sum=0,p[v],count=0,v1,v2;
            for(i=0;i<v;i++)
                p[i]=i;
                while(count<v)
                {
                    min=999;
                    for(i=0;i<v;i++)
                    {
                        for(j=0;j<v;j++)
                        {
                            if(adj[i][j]<min)
                            {
                                min=adj[i][j];
                                v1=i;
                                v2=j;
                            }
                        }
                    }
                    if(min==999)break;
                    i=find(v1,p);
                    j=find(v2,p);
                    if(i!=j)
                    {
                        t[k][0]=i;
                        t[k][1]=j;
                        k++;

                        sum+=min;
                        count++;
                        unionij(i,j,p);

                    }
                    adj[v1][v2]=adj[v2][v1]=999;
                }
                if(count==v-1)
                {
                    cout<<"Spanning tree is:"<<endl;
                    for(i=0;i<v-1;i++)
                        cout<<"Edge "<<t[i][0]<<"-->"<<t[i][1]<<endl;
                    cout<<endl<<"Cost : "<<sum<<endl;
                    return;
                }

            cout<<"Spanning tree doesn't exist"<<endl;

        }
};
int main()
{
    graph g;
    g.read();
    g.kruskal();
}
