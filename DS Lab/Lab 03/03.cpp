#include <iostream>
using namespace std;

int main() {
    
    int sectionsCount, racksCount;

    cout << "Enter no. of sections in the library: ";
    cin >> sectionsCount;

    cout << "Enter no. of racks in each section: ";

    int** library = new int*[racksCount];
    
    for(int i = 0; i < racksCount; i++) {
        library[i] = new int[racksCount];
    }
    
    // Storing books info in 2D dynammic array
    for(int i = 0; i < sectionsCount; i++) {
        cout << "\nSection #" << i+1 << ":\n";
        for(int j = 0; j < racksCount; j++) {
            cout << "\tEnter no. of books in Rack #" << j+1 << ": ";
            cin >> library[i][j];
        }
    }
    cout << endl;

    // Finding section with max no. of books
    int maxSection = -1, maxBooks = -1;
    for(int i = 0; i < sectionsCount; i++) {
        if(sectionsCount > maxSection) maxSection = sectionsCount;
        for(int j = 0; j < racksCount; j++) {
            if((*library[i] * library[i][j]) > maxBooks) maxBooks = (*library[i] * library[i][j]);
        }
        
    }

    for(int i = 0; i < racksCount; i++) {
        cout << "No. of books in the rack #" << i+1 << ": " << racks[i] << endl;
    }
        
    return 0;
}
