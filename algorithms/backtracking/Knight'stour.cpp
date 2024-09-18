//
// C/C++ program of Knight's Tour using Backtracking
//
// The All ▲lgorithms Project

// https://github.com/allalgorithms/cpp
//
// Contributed by: Prayag Thakur
// Github: @PrAyAg9
//

#include <iostream>
#include <vector>
#define N 8 // Chessboard is N x N (8 x 8 in this case)
using namespace std;

// Utility function to check if the move is valid
bool isSafe(int x, int y, vector<vector<int>> &board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Utility function to print the board
void printSolution(const vector<vector<int>> &board) {
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            cout << board[x][y] << "\t";
        }
        cout << endl;
    }
}

// A recursive utility function to solve Knight Tour problem
bool solveKnightTour(int x, int y, int movei, vector<vector<int>> &board,
                     const vector<int> &moveX, const vector<int> &moveY) {
    int nextX, nextY;
    // Base case: If all squares are visited, return true
    if (movei == N * N)
        return true;

    // Try all next moves from the current coordinate x, y
    for (int k = 0; k < 8; ++k) {
        nextX = x + moveX[k];
        nextY = y + moveY[k];
        if (isSafe(nextX, nextY, board)) {
            board[nextX][nextY] = movei;
            if (solveKnightTour(nextX, nextY, movei + 1, board, moveX, moveY))
                return true;
            else
                // Backtrack: Undo the current move
                board[nextX][nextY] = -1;
        }
    }
    return false;
}

// This function solves the Knight Tour problem using Backtracking.
// This function mainly uses solveKnightTour() to solve the problem.
bool knightTour() {
    // Initialize the chessboard with -1 (unvisited squares)
    vector<vector<int>> board(N, vector<int>(N, -1));

    // The knight's possible moves in the x and y directions
    vector<int> moveX = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> moveY = {1, 2, 2, 1, -1, -2, -2, -1};

    // Knight starts at the first block (0, 0)
    board[0][0] = 0;

    // Start the Knight's Tour from the first position
    if (!solveKnightTour(0, 0, 1, board, moveX, moveY)) {
        cout << "Solution does not exist." << endl;
        return false;
    } else
        printSolution(board);

    return true;
}

int main() {
    knightTour();
    return 0;
}
