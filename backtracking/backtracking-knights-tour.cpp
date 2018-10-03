#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

int board[20][20];

bool KnightTour(int n,int m,int moveNumber,int row,int col) {

	if (row >= n || row < 0 || col >= m || col < 0)
		return false;

	if (board[row][col] != -1)
		return false;

	if (moveNumber == n*m - 1) {

		board[row][col] = moveNumber;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout<<" "<<setw(2)<<board[i][j]<<" ";
			}
			cout << endl;
		}
	//	board[row][col] = -1;
		return true;
	}


	board[row][col] = moveNumber;



	if (KnightTour(n, m,moveNumber + 1, row +1, col + 2)) {
		return true;
	}
	if (KnightTour(n, m,moveNumber + 1, row -1, col +2)) {
		return true;
	}
	if (KnightTour(n, m,moveNumber + 1, row + 1, col -2)) {
		return true;
	}
	if (KnightTour(n, m,moveNumber + 1, row -1, col -2)) {
		return true;
	}
	if (KnightTour(n, m,moveNumber + 1, row - 2, col + 1)) {
		return true;
	}
	if (KnightTour(n, m,moveNumber + 1, row - 2, col - 1)) {
		return true;
	}
	if (KnightTour(n,m, moveNumber + 1, row + 2, col + 1)) {
		return true;
	}
	if (KnightTour(n,m, moveNumber + 1, row + 2, col - 1)) {
		return true;
	}

	board[row][col] = -1;

	return false;


}

int main()
{
	int n,m;
	cout<<"Enter n,m : ";
	cin >> n>>m;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			board[i][j] = -1;
		}
	}
	//board[0][0] = 0;


	if (!KnightTour(n,m, 0, 0, 0)) {
		cout << "No solution";
	}

	//_getch();
    return 0;
}

