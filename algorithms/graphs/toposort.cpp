#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
priority_queue<int,vector<int>,greater<int> >q;
queue<int>a;
bool visited[10001];
int indegree[10001];
int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	while(m--)
	{
	    scanf("%d%d",&u,&v);
	    adj[u].push_back(v);
	    indegree[v]++;
	}
	for(int i=1;i<=n;i++)
	    if(!indegree[i])
	        q.push(i);
	int k=0;
	while(!q.empty())
	{
	    int u=q.top();
	    q.pop();
	    a.push(u);
	    for(auto it:adj[u])
	    {
	        indegree[it]--;
	        if(!indegree[it])
	            q.push(it);
	    }
	    ++k;
	}
	if(k!=n)
	    printf("Sandro fails.");
	else
	{
	    while(!a.empty())
	    {
	        printf("%d ",a.front());
	        a.pop();
	    }
	}
}
