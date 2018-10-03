#include<iostream>
using namespace std;

bool findPath(int maze[][20],int n,int x,int y,int path[][20]){
	if(x<0||x>=n||y<0||y>=n)
	return false;

	if(x == n - 1 && y == n - 1){

	path[x][y]=1;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cout<<path[i][j]<<" ";

		cout<<endl;
	} cout<<endl;

	return true;
	}


	if(maze[x][y] == 0||path[x][y]==1)
	return false;

	path[x][y]=1;

	// Right
		if(findPath(maze, n, x, y + 1, path)){
			path[x][y] = 0;
			return true;
		}
		//left

		if(findPath(maze, n, x, y - 1, path)){
		    path[x][y] = 0;
			return true;
		}

		// top

		if(findPath(maze, n, x - 1, y, path)){
			path[x][y] = 0;
			return true;
		}

		// Down

		if(findPath(maze, n , x + 1, y, path)){
			path[x][y] = 0;
			return true;
		}

    path[x][y] = 0;
    return false;

}


bool jfindPath(int maze[][20],int n){

	int path[20][20]={0};  //set all to 0
	return findPath(maze,n,0,0,path);

}


int main(){
	int n=3;
	int maze[20][20]={{1,1,0},
					  {1,1,0},
					  {0,1,1}};

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cout<<maze[i][j]<<" ";

		cout<<endl;
	} cout<<endl;

	cout<<jfindPath(maze,n);

	return 0;
}
