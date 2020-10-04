#include<bits/stdc++.h>
using namespace std;
char mx[100][100];
bool visited[100][100];
int V,E,k,l,N,M;
bool isvalid(int x,int y)
{
    if(x<=N && y<=M && x>=1 && y>=1)
        return true;
    return false;
}
bool bfs(int x,int y)
{
    for(int i=1;i<100;i++)
        for(int j=1;j<100;j++)
        visited[i][j]=0;
queue<pair<int,int > > q;
q.push({x,y});
visited[x][y]=1;
while(!q.empty())
{
     x=q.front().first;
    y=q.front().second;
    visited[x][y]=true;
    q.pop();
    if(isvalid(x,y+1) && !visited[x][y+1] && mx[x][y+1]==mx[x][y])
    q.push({x,y+1});
    if(isvalid(x,y-1) && !visited[x][y-1] && mx[x][y-1]==mx[x][y])
    q.push({x,y-1});
    if(isvalid(x+1,y) && !visited[x+1][y] && mx[x+1][y]==mx[x][y])
    q.push({x+1,y});
    if(isvalid(x-1,y) && !visited[x-1][y] && mx[x-1][y]==mx[x][y])
    q.push({x-1,y});
    int counter=0;
    if(visited[x][y+1])
        counter++;
    if(visited[x][y-1])
    counter++;
    if(visited[x+1][y])
        counter++;
    if(visited[x-1][y])
        counter++;
    if(counter>1)
        return true;
 
}
return false;
}
 
int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        cin>>mx[i][j];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        if( bfs(i,j)){
            cout<<"Yes";
    return 0;
        }
 
    cout<<"No";
 
 
 
    return 0;
}
