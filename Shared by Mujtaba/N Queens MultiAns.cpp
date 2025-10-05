#include<iostream>
using namespace std;

int totalSolutions = 0;

bool isSafe(char** board,int rowNum,int colNum,int n){
    // check column
    for (int i = 0; i < rowNum; i++){
        if(board[i][colNum] == 'Q')
            return false;
    }

    // check upper-left diagonal
    for (int i = rowNum - 1, j = colNum - 1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q')
            return false;
    }

    // check upper-right diagonal
    for (int i = rowNum - 1, j = colNum + 1; i >= 0 && j < n ; i--, j++){
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void printSol(char** board,int n){
    for (int i=0; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void placeQueens(char** board, int rowNum,int n){
    if(rowNum == n){ //checks if the rowNum is equal to size of matrix
        printSol(board,n);
        totalSolutions++;
        return;
    }

    for(int colNum = 0 ; colNum<n ; colNum++){
        if(isSafe(board,rowNum,colNum,n)){
            board[rowNum][colNum] = 'Q'; // place queen
            placeQueens(board,rowNum+1,n); // recurse
            board[rowNum][colNum] = '.'; // backtrack when rowNum becomes 4 when recursing, checked in base case 
        }
    }
}

int main(){
    int n;  // n = no.of rows & columns of matrix
    cout<<"Enter size of board: ";
    cin>>n;
    char** board = new char*[n];
    for (int i = 0; i < n; i++){
        board[i] = new char[n];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            board[i][j] = '.';
        }
    }

    placeQueens(board, 0,n);
    cout << "\nTotal solutions: " << totalSolutions<< endl;

    for (int i = 0; i < n ; i++){
        delete[] board[i];
    }
    delete[] board;

    return 0;
}