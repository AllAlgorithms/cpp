
/*Start in the leftmost column
1) If all queens are placed
    return true
2) Try all rows in the current column.  Do following for every tried row.
    a) If the queen can be placed safely in this row then mark this [row,column]
        as part of the solution and recursively check if placing queen here leads to a solution.
    b) If placing queen in [row, column] leads to a solution then return true.
    c) If placing queen doesn't lead to a solution then umark this [row,column] (Backtrack) 
       and go to step (a) to try other rows.
3) If all rows have been tried and nothing worked, return false to trigger backtracking.*/

#include <iostream>
using namespace std;

char board[30][30];

void printBoard(char arr[][30], int n) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << arr[r][c] << " " ;
        }
        cout << endl;
    }
}

void initialiseBoard(int n) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            board[r][c] = 'X';
        }
    }
}

bool canPlace(char board[][30], int N, int x, int y)
{
    //check the row if aqueen already exists
    for (int r = 0; r < N; ++r)
    {
        if (board[r][y] == 'Q') 
            return false;
    }

    int rInc[] = { -1, +1, +1, -1};
    int cInc[] = { -1, +1, -1, +1};
     //check diagonal if queen already exists
    for (int dir = 0; dir < 4; ++dir)
    {
        int rowAdd = rInc[dir];
        int colAdd = cInc[dir];
        int r = x + rowAdd;
        int c = y + colAdd;
        //check that r c is within the board
        while (r >= 0 && r < N && c >= 0 && c < N)
        {
            if (board[r][c] == 'Q')
             return false;
            r = r + rowAdd;
            c = c + colAdd;
        }
    }
    return true;
}

bool nqueen(int r, int n)
{
    if (r == n)//base case if all queens are placed 
    {
        return true;
    }
    //for every column, use hit and trial by placing a queen in the each cell of curr Row
    for (int c = 0; c < n; ++c)
    {
        int x = r;
        int y = c;
        //check if queen can be placed on board[i][c]
        if (canPlace(board, n, x, y)==true)
        {
            board[x][y] = 'Q'; //place queen in each column
            bool isSuccessful = nqueen(r + 1, n);   //recursion to place rest of queens
            if (isSuccessful == true)
             return true;
            board[x][y] = 'X';   //else unmark the cell or backtrack
        }
    }
    return false; //if queen cannot be placed in any row in this column then return false
}

int main()
{
    int n;
    cin >> n;

    initialiseBoard(n);//initialse all the board with X
    bool isSuccessful = nqueen(0, n);

    if (isSuccessful) printBoard(board, n);
    else cout << "Sorry You need to have a larger board!\n";

    return 0;
}
