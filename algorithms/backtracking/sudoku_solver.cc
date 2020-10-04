/*
https://leetcode.com/problems/sudoku-solver/

Sudoku Solver
==============

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

![before filled](http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
A sudoku puzzle...

![after filled](http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)
...and its solution numbers marked in red.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    static const int kSize = 9;
    bool rowUsed[kSize][kSize];
    bool colUsed[kSize][kSize];
    bool areaUsed[kSize][kSize];

public:
    bool backtrack(vector<vector<char> >& board, int r, int c) {
        if(r >= kSize) return true; // the last cell.
        if(c >= kSize) return backtrack(board, r+1, 0); // row complete, move to next row.
        if(isdigit(board[r][c])) return backtrack(board, r, c+1); // skip the given cell.

        // empty cell, try each value [0-9] to fill it.
        for(int num = 1; num <= kSize; ++num) {
            int area = (r/3) * 3 + (c/3);
            if(rowUsed[r][num] || colUsed[num][c] || areaUsed[area][num]) {
                continue;
            }

            // emplace num as char.
            board[r][c] = num + '0';
            rowUsed[r][num] = colUsed[num][c] = areaUsed[area][num] = true;

            // try next position...
            if(backtrack(board, r, c+1)) return true; // stop searching when the first solution found.

            // can not continue to place, backtrack.
            board[r][c] = '.';
            rowUsed[r][num] = colUsed[num][c] = areaUsed[area][num] = false;
        }
        return false;
    }

    void solveSudoku(vector<vector<char> >& board) {
        memset(rowUsed, false, sizeof(rowUsed));
        memset(colUsed, false, sizeof(colUsed));
        memset(areaUsed, false, sizeof(areaUsed));
        vector<vector<char> > result(board);
        if (backtrack(result, 0, 0)) { // found solution
            board = result; // copy back
        }
    }
};

template<typename Matrix>
void printMatrix(Matrix m)
{
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            cout << m[i][j];
        }
        cout << "\n";
    }
    cout << endl;
}

// get sudoku puzzle from sudokupuzzle.org:
// curl -s "http://sudokupuzzle.org/online2.php?nd=0&y=`date +%Y\&m=%m\&d=%d`" | grep tmda= | sed "s/.*tmda='//g" | cut -c -81

int main(int argc, char* argv[])
{
    const int N = 9;
    vector<vector<char> > board;
    string puzzle = argc > 1 ? argv[1] : "000005001097004000005620008951060873804510209063700050149076080032041690780350402";

    board.resize(N);
    for (int i = 0; i < N; i++) {
        board[i].resize(N);
        for (int j = 0; j < N; j++) {
            const char c = puzzle[i*N + j];
            board[i][j] = (c == '0' ? '.' : c);
        }
    }
    printMatrix(board);

    Solution().solveSudoku(board);
    printMatrix(board);

    return 0;
}

