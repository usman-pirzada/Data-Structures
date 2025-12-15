#include <iostream>
#include <conio.h>
using namespace std;

class Node {
public:
    char** visitedArr;
    Node* next;

    Node(char** visitedArr, int h, int w) : next(nullptr) {
        this->visitedArr = new char*[h];
        for(int i = 0; i < h; i++) {
            this->visitedArr[i] = new char[w];

            for(int j = 0; j < w; j++) {
                this->visitedArr[i][j] = visitedArr[i][j];
            }
        }
    }
};

class List {
    Node* head;

public:
    List() : head(nullptr) {};

    void push(char** arr, int h, int w) {
        Node* newNode = new Node(arr, h, w);

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    char** getVisitedArr(int idx) {
        if(head == nullptr) {
            return NULL;
        }

        int count = 0;
        Node* temp = head;

        while (count < idx) {
            temp = temp->next;
            count++;

            if(temp == nullptr) {
                return NULL;
            }
        }
        
        return temp->visitedArr;
    }
};

// Compares two 2D arrays of same size
bool is_equal(char** arr, char** otherArr, int h, int w) {
    
    if(!arr || !otherArr || h <= 0 || w <= 0) {
        return false;
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(arr[i][j] != otherArr[i][j]) {
                return false;
            }
        }
    }

    return true;
}

// Check whether the current puzzle arrangement is already visited
bool is_visited(char** puzzle, int h, int w, List& visited) {
    int idx = 0;
    while(visited.getVisitedArr(idx) != NULL)  {
        if(is_equal(puzzle, visited.getVisitedArr(idx), h, w)) {
            return true;
        }
        idx++;
    }

    return false;
}

void tiltBox(char** puzzle, int h, int w, string dir) {
    if(dir == "Up") {
        for (int i = 0; i < w; i++) {
            for (int sweep = 0; sweep < h; sweep++) {
                for (int j = 1; j < h; j++) {
                    if(puzzle[j - 1][i] == '.' && puzzle[j][i] != '.') {
                        puzzle[j - 1][i] = puzzle[j][i];
                        puzzle[j][i] = '.';
                    }
                }
            }
        }

    } else if(dir == "Down") {
        for (int i = w - 1; i >= 0; i--) {
            for (int sweep = 0; sweep < h; sweep++) {
                for (int j = h - 1; j > 0; j--) {
                    if(puzzle[j][i] == '.' && puzzle[j - 1][i] != '.') {
                        puzzle[j][i] = puzzle[j - 1][i];
                        puzzle[j - 1][i] = '.';
                    }
                }
            }
        }
        

    } else if(dir == "Right") {
        for (int i = h - 1; i >= 0; i--) {
            for (int sweep = 0; sweep < w; sweep++) {   // Repeat 'w' times to ensure all elements are moved to right
                for (int j = w - 1; j > 0; j--) {
                    if(puzzle[i][j] == '.' && puzzle[i][j - 1] != '.') {
                        puzzle[i][j] = puzzle[i][j - 1];
                        puzzle[i][j - 1] = '.';
                    }
                }
            }
        }

    } else if(dir == "Left") {
        for (int i = 0; i < h; i++) {
            for (int sweep = 0; sweep < w; sweep++) {   // Repeat 'w' times to ensure all elements are moved to right
                for (int j = 1; j < w; j++) {
                    if(puzzle[i][j - 1] == '.' && puzzle[i][j] != '.') {
                        puzzle[i][j - 1] = puzzle[i][j];
                        puzzle[i][j] = '.';
                    }
                }
            }
        }

    } else {
        cout << "\nInvalid Tilt Direction!!";
    }
}

// void reverseMove(char** puzzle, int h, int w, string moves[], int movesCount) {
//     for (int i = movesCount - 1; i >= 0; i--) {
//         string dir = moves[i];

//         if(dir == "Up") {
//             tiltBox(puzzle, h, w, "Down");

//         } else if(dir == "Down") {
//             tiltBox(puzzle, h, w, "Up");

//         } else if(dir == "Right") {
//             tiltBox(puzzle, h, w, "Left");

//         } else if(dir == "Left") {
//             tiltBox(puzzle, h, w, "Right");
            
//         }
//     }
// }

bool solvePuzzle(char** puzzle, int h, int w, char** solPuzzle, List& visited) {
    if(is_equal(puzzle, solPuzzle, h, w)) {
        return true;
    }

    if(is_visited(puzzle, h, w, visited)) {
        return false;
    }

    visited.push(puzzle, h, w);

    string directions[] = {"Up", "Down", "Right", "Left"};
    for(string dir : directions) {
        // Temporary puzzle copy to test moves; will be discarded if unsuccessful and kept if solution is found
        char** tempPuzzle = new char*[h];
        for(int i = 0; i < h; i++) {
            tempPuzzle[i] = new char[w];

            for(int j = 0; j < w; j++) {
                tempPuzzle[i][j] = puzzle[i][j];
            }
        }
        
        tiltBox(tempPuzzle, h, w, dir);

        if(solvePuzzle(tempPuzzle, h, w, solPuzzle, visited)) {
            return true;
        }
    }

    return false;
}

int main() {

    int h, w;   // 'h' (rows) AND 'w' (columns)
    while (1) {
        cin >> h >> w;

        if((h > 0 && h <= 500 && w > 0 && w <= 500)) break;

        cout << "Invalid Input!! [Hint: (1 <= h, w <= 500)]";
    }

    char** puzzleBox = new char*[h];
    for (int i = 0; i < h; i++) {
        puzzleBox[i] = new char[w];
    }
    
    // Input starting arrangement
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            puzzleBox[i][j] = getche();
        }
        cout << "\n";
    }
    cout << "\n";
    
    char** solPuzzleBox = new char*[h];
    for (int i = 0; i < h; i++) {
        solPuzzleBox[i] = new char[w];
    }

    // Input ending arrangement
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            solPuzzleBox[i][j] = getche();
        }
        cout << "\n";
    }
    cout << "\n";

    // for (int i = 0; i < h; i++) {
    //     for (int j = 0; j < w; j++) {
    //         cout << puzzleBox[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    List visited;

    if(solvePuzzle(puzzleBox, h, w, solPuzzleBox, visited)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    
    return 0;
}
