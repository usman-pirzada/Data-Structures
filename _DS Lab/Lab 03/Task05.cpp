#include <iostream>
using namespace std;

int main() {
    int players, matches;
    cin >> players >> matches;

    int** scores = new int*[players];
    for(int i = 0; i < players; i++) scores[i] = new int[matches];

    for(int i = 0; i < players; i++)
        for(int j = 0; j < matches; j++)
            cin >> scores[i][j];

    int bestPlayer = 0, bestTotal = 0;
    int bestMatch = 0, bestMatchScore = 0;

    for(int i = 0; i < players; i++) {
        int total = 0;
        for(int j = 0; j < matches; j++) total += scores[i][j];
        cout << "Player " << i+1 << " - Total: " << total 
             << ", Average: " << (double)total/matches << endl;
        if(total > bestTotal) {
            bestTotal = total;
            bestPlayer = i;
        }
    }

    for(int j = 0; j < matches; j++) {
        int sum = 0;
        for(int i = 0; i < players; i++) sum += scores[i][j];
        if(sum > bestMatchScore) {
            bestMatchScore = sum;
            bestMatch = j;
        }
    }

    cout << "Player " << bestPlayer+1 << " had the highest total score (" << bestTotal << ")" << endl;
    cout << "Match " << bestMatch+1 << " had the highest combined score (" << bestMatchScore << ")" << endl;

    for(int i = 0; i < players; i++) delete[] scores[i];
    delete[] scores;
}