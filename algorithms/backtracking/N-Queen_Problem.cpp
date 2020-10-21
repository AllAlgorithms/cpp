#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

void queen(int row,int n);
int board[20], sol_count;

void print(int n)
{
	int i, j;
	sol_count++;
	printf("\nSolution %d:\n`", sol_count);
	for(i=1; i<=n; ++i)
		printf("\t%d",i);
	for(i=1; i<=n; ++i)
	{
		printf("\n\n%d\t",i);
		for(j=1; j<=n; ++j)
		{
			if(board[i]==j)
				printf("Q%d\t",i);
			else
				printf("--\t");
		}
	}
}

int place(int row, int column)
{
	int i;
	for(i=1; i<=row-1; ++i)
	{
		if(board[i]==column)
			return 0;
		else
			if(abs(board[i]-column)==abs(i-row))
				return 0;
	}
	return 1;
}

void queen(int row, int n)
{
	for(int column=1; column<=n; ++column)
	{
		if(place(row, column))
		{
			board[row]=column;
			if(row==n)
				print(n);
			else
				queen(row+1, n);
		}
	}
}

int main()
{
	int n, i, j;
	printf(".....N Queens Problem Using Backtracking.....\n");
	printf("Enter number of Queens: ");
	scanf("%d",&n);
	queen(1, n);
}