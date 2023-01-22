#include<bits/stdc++.h>
using namespace std;

struct myQueue{
    int x, y;
    double g, h, f ;
    bool flag ;
}Q[100], temp,par[100][100];


int grid[100][100] ;
double heuristicCost[100][100], dis[100][100] ;

void initialization(int n, int m, int stri, int strj)
{
    int k = 0 ;
    dis[stri][strj] = 0.0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            Q[k].x = i ;
            Q[k].y = j ;
            Q[k].g = dis[i][j] ;
            Q[k].h = heuristicCost[i][j] ;
            Q[k].f = Q[k].g + Q[k].h ;
            Q[k].flag = true ;
            k++ ;
        }
    }
}

bool isEmpty(int n, int m){
    for(int i = 0 ; i < n*m ; i++){
        if(Q[i].flag)
		return false ;
    }
    return true ;
}

int pop(int n, int m)
{
    int min = 1000000 ;
    int index ;
    for(int i = 0 ; i < n*m ; i++)
    {
        if(Q[i].f < min && Q[i].flag == true){
            min = Q[i].f ;
            index = i ;
        }
    }
    Q[index].flag = false ;
    return index ;
}

void updateQueueCost(int i, int j, double cost, int n, int m){
    for(int k = 0 ; k < n*m ; k++){
        if(Q[k].x == i && Q[k].y == j){
            Q[k].g = cost ;
            Q[k].f = Q[k].g + Q[k].h ;
        }
    }
}
void aStarSearch(int n, int m)
{
    while(!isEmpty(n, m)){
        int index = pop(n,m) ;
        temp = Q[index] ;
        int i = temp.x ;
        int j = temp.y ;
        if(grid[i-1][j] > -1){
            if(dis[i-1][j] > dis[i][j] + grid[i-1][j]){
                dis[i-1][j] = dis[i][j] + grid[i-1][j];
                par[i-1][j].x = i;
                par[i-1][j].y = j;
                updateQueueCost(i-1, j, dis[i-1][j], n, m);
            }
        }

        if(grid[i+1][j]>-1){
            if(dis[i+1][j] > dis[i][j]+grid[i+1][j]){
                dis[i+1][j] = dis[i][j] + grid[i+1][j];
                par[i+1][j].x = i;
                par[i+1][j].y = j;
                updateQueueCost(i+1, j, dis[i+1][j], n, m);
                cout<<"i,j: "<<i<<","<<j<<"\n";
            }
        }

        if(grid[i][j-1]>-1){
            if(dis[i][j-1] > dis[i][j]+grid[i][j-1]){
                dis[i][j-1] = dis[i][j]+grid[i][j-1];
                par[i][j-1].x = i;
                par[i][j-1].y = j;
                updateQueueCost(i, j-1, dis[i][j-1], n, m);
                cout<<"i,j: "<<i<<","<<j<<"\n";
            }
        }
        if(grid[i][j+1]>-1){
            if(dis[i][j+1] > dis[i][j]+grid[i][j+1]){
                dis[i][j+1] = dis[i][j]+grid[i][j+1];
                par[i][j+1].x = i;
                par[i][j+1].y = j;
                updateQueueCost(i, j+1, dis[i][j+1], n, m);
                cout<<"i,j: "<<i<<","<<j<<"\n";
            }
        }
    }

}

int main()
{
    int n, m, i , j ;
    int stri, strj, dsti, dstj ;
    scanf("%d %d", &n, &m) ;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            scanf("%d", &grid[i][j]) ;

        }
    }
    scanf("%d %d %d %d", &stri, &strj, &dsti, &dstj) ;
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            heuristicCost[i][j] = sqrt(pow((1.00*dsti-i),2)+pow((1.00*dstj-j),2)) ;//destination between starting and destination node
            dis[i][j] = 99999.00 ;
        }
    }
    /*for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            printf("%.3lf ", heuristicCost[i][j]) ;
        }
        printf("\n") ;
    }*/
    initialization(n, m, stri, strj) ;
    aStarSearch(n, m) ;
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";

    while(par[dsti][dstj].x != stri || par[dsti][dstj].y!=strj){
        cout<<"("<<dsti<<","<<dstj<<")<--";
        dsti = par[dsti][dstj].x;
        dstj = par[dsti][dstj].y;
    }cout<<"("<<stri<<", "<<strj<<")";
    /*for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<par[i][j].x<<","<<par[i][j].y<<" ";
        }
        cout<<"\n";
    }*/


}
/*
4 4
2 5 3 4
-1 1 7 3
4 2 6 8
5 2 1 3
0 0
3 3
*/

