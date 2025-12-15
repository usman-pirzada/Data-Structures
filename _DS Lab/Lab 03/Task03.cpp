#include <iostream>
using namespace std;

int main() {
    int sectionsCount, racksCount;

    cout << "Enter no. of sections in the library: ";
    cin >> sectionsCount;

    cout << "Enter no. of racks in each section: ";
    cin >> racksCount;

    int** library = new int*[sectionsCount];
    for(int i = 0; i < sectionsCount; i++) {
        library[i] = new int[racksCount];
    }

    for(int i = 0; i < sectionsCount; i++) {
        cout << "\nSection #" << i+1 << ":\n";
        for(int j = 0; j < racksCount; j++) {
            cout << "\tEnter no. of books in Rack #" << j+1 << ": ";
            cin >> library[i][j];
        }
    }

    int maxBooks = -1, maxSection = -1, totalBooks = 0;
    for(int i = 0; i < sectionsCount; i++) {
        int sectionSum = 0;
        for(int j = 0; j < racksCount; j++) {
            sectionSum += library[i][j];
        }
        totalBooks += sectionSum;
        if(sectionSum > maxBooks) {
            maxBooks = sectionSum;
            maxSection = i;
        }
    }

    cout << "\nSection #" << maxSection+1 << " has the maximum number of books: " << maxBooks << endl;
    cout << "Total number of books in the library: " << totalBooks << endl;

    for(int i = 0; i < sectionsCount; i++) {
        delete[] library[i];
    }
    delete[] library;

    return 0;
}