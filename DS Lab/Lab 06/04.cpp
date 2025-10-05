#include <iostream>
using namespace std;

void printSol(char** board, int n) {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << "\t";
        }
        cout << "\n";
    }
}

void printAllNQueens(char** board, int n, int& solCount) {
    cout << "\nSolution " << solCount << ":\n";
    printSol(board, n);
    solCount++;
}

bool isSafe(char** board, int n, int row, int col) {
    // int i, j;

    for (int i=0; i < col; i++) {
        if(board[row][i] == 'Q') {
            return false;
        }
    }

    for (int i=row, j=col; i >= 0 && j >= 0; i--, j--) {    // Check left diagonal
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    for (int i=row, j=col; i < n && j >= 0; i++, j--) {    // Check right diagonal
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

bool NQueensUtil(char** board, int n, int col, int& solCount) {
    if (col == n) {
        printAllNQueens(board, n, solCount);
        return false;
    }

    bool foundSolution = false;
    for (int row = 0; row < n; row++) {
        if(isSafe(board, n, row, col)) {
            board[row][col] = 'Q';
            
            // Recursive call - collect result but don't return immediately
            bool result = NQueensUtil(board, n, col+1, solCount);
            foundSolution = foundSolution || result;
            
            board[row][col] = '.';
        }
    }

    return false;
}

void solveNQueens(int n) {
    // 2D array initialization
    char** board = new char*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new char[n];
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    int solCount = 1;
    if(!NQueensUtil(board, n, 0, solCount)) {
        if (solCount == 1) { // No solutions found
            cout << "No solution exists!!" << endl;
        }
    }
    
    cout << "\nTotal solutions: " << solCount - 1 << endl;
    
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;
}

int main() {
    int n;

    cout << "Enter the size of chessboard: ";
    cin >> n;

    solveNQueens(n);
    
    return 0;
}
