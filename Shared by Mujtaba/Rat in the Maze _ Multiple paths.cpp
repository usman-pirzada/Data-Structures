#include<iostream>
using namespace std;
#define n 5

bool isSafe(int maze[n][n],int i,int j,int sol[n][n]){
    return (i >= 0 && i < n && j >= 0 && j < n && maze[i][j] == 1 && sol[i][j] == 0);
}

void print(int maze[n][n]){
    for(int i=0;i<n;i++){
        for (int j = 0;j<n;j++){
            cout << maze[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void solveMaze(int maze[n][n],int i,int j,int sol[n][n], char* paths,int index){
    if(i==4 && j==2 && maze[i][j]==1){
        paths[index] = '\0';
        cout << paths << endl;
        return;
    }

    sol[i][j] = 1;

    // down
    if(isSafe(maze,i+1,j,sol)){
        paths[index] = 'D';
        solveMaze(maze,i+1,j,sol,paths,index+1);
    }

    // right
    if(isSafe(maze,i,j+1,sol)){
        paths[index] = 'R';
        solveMaze(maze,i,j+1,sol,paths,index+1);
    }

    // left
    if(isSafe(maze,i,j-1,sol)){
        paths[index] = 'L';
        solveMaze(maze,i,j-1,sol,paths,index+1);
    }

    // up
    if(isSafe(maze,i-1,j,sol)){
        paths[index] = 'U';
        solveMaze(maze,i-1,j,sol,paths,index+1);
    }

    sol[i][j] = 0;
}

int main(){
    int maze[n][n] = {
        {1,1,0,0,0},
        {0,1,1,1,0},
        {1,1,0,1,1},
        {1,0,0,0,1},
        {1,1,1,1,1}
    };
    int sol[n][n] = {0};

    char* paths = new char[50];

    if(maze[0][0]==1){
        cout << "\nPossible Solutions To The Maze:\n";
        solveMaze(maze,0,0,sol,paths,0);
    } else{
        cout << "\nThe start is blocked";
    }

    delete[] paths;

    return 0;
}