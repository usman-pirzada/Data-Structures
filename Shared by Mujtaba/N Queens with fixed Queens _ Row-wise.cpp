#include <iostream>
#define n 4
using namespace std;
void solution(int board[n][n]) {
    for (int i = 0; i < n; i++)

    {
        cout << "\n";
        for (int j = 0; j < n; j++)
        {
            cout << " " << board[i][j];
        }
    }
}
bool isSafe(int board[n][n], int row, int col)
{
 
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }
   
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
   
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

bool solveNqueen(int board[n][n], int row)
{
    if (row >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i))
        {
            board[row][i] = 1;
            if (solveNqueen(board, row + 1))
            {
                return true;
            }
            board[row][i] = 0;
           
        }

    }
    return false;
}
bool solve()
{
    int board[n][n] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    if (solveNqueen(board, 0) == false)
    {
        cout << "Solution does not exist" << endl;
        return false;
    }
    solution(board);
    return true;
}
int main()
{
    solve();
    return 0;
}