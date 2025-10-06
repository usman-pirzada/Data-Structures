#include <iostream>
using namespace std;

#define n 6

void printSolMaze(const char sol[n][n], const int& energy) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Energy Remaining after reaching Treasure Room: " << energy << "%" << endl;
}

bool isSafe(const char maze[n][n], int row, int col, const char sol[n][n], int& energy) {
    if (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] != 'D' && sol[row][col] == '0' && energy > 0) {
        if(maze[row][col] == 'P' || maze[row][col] == 'S' || maze[row][col] == 'T')
            return true;

        if(maze[row][col] == 'H') {
            energy -= 5;
            return true;
        }
    }

    return false;
}

bool solveMaze(const char maze[n][n], int row, int col, char sol[n][n], int& energy) {
    if(row == n-1 && col == n-1 && maze[row][col] == 'T') {
        sol[row][col] = maze[row][col];
        cout << "\nSolution Path:\n";
        printSolMaze(sol, energy);
        return true;
    }

    if(isSafe(maze, row, col, sol, energy)) {
        sol[row][col] = maze[row][col];

        int tempEnergy = energy;
        bool foundPath = false;

        // Check Down
        if(solveMaze(maze, row+1, col, sol, energy)) {
            return true;
        }

        energy = tempEnergy;

        // Check Left
        if(solveMaze(maze, row, col-1, sol, energy)) {
            foundPath = true;
        }

        energy = tempEnergy;

        // Check Right
        if(solveMaze(maze, row, col+1, sol, energy)) {
            foundPath = true;
        }

        energy = tempEnergy;

        // Check Up
        if(solveMaze(maze, row-1, col, sol, energy)) {
            foundPath = true;
        }

        sol[row][col] = '0';
        return foundPath;
    }

    return false;
}

int main() {
    char maze[n][n] = {
        {'S', 'P', 'P', 'D', 'H', 'H'},
        {'P', 'P', 'P', 'D', 'P', 'H'},
        {'P', 'H', 'P', 'P', 'P', 'D'},
        {'P', 'D', 'P', 'D', 'P', 'P'},
        {'P', 'P', 'P', 'H', 'P', 'D'},
        {'P', 'D', 'P', 'P', 'P', 'T'}
    };

    char sol[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sol[i][j] = '0';
        }
    }

    int energy = 100;
    if(!solveMaze(maze, 0, 0, sol, energy)) {
        cout << "\n No solution exists!!";
    }
    
    return 0;
}
