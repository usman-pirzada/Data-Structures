#include <iostream>
using namespace std;

class Librarian {
    string name;
    int id;
    int experienceYears;
    static const int fixedBooksCount = 4;
    int fixedBooksIDs[fixedBooksCount];

    int booksCount;
    int* bookIDs;

public:
    Librarian(string name, int id, int experienceYears) {
        this->name = name;
        this->id = id;
        this->experienceYears = experienceYears;
        this->booksCount = booksCount;
        bookIDs = new int[booksCount];
    }

    Librarian(const Librarian& otherLibrarian) {
        name = otherLibrarian.name;
        id = otherLibrarian.id;
        experienceYears = otherLibrarian.experienceYears;
    }

    ~Librarian() {
        delete[] bookIDs;
    }

    Librarian& operator=(const Librarian& otherLibrarian) {
        if(this == &otherLibrarian)
            return *this;

        name = otherLibrarian.name;
        id = otherLibrarian.id;
        experienceYears = otherLibrarian.experienceYears;
        booksCount = otherLibrarian.booksCount;

        delete bookIDs;

        bookIDs = new int[otherLibrarian.booksCount];
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Experience Years: " << experienceYears << endl;
    }

    void setFixedBooksIDs(int fixedBookIDs[]) {
        for (int i = 0; i < fixedBooksCount; i++) {
            fixedBookIDs[i] = fixedBookIDs[i];
        }
    }

    int* getFixedBooksIDs() {
        return fixedBooksIDs;
    }

    void setBooksCapacity(int booksCount) {
        this->booksCount = booksCount;
        bookIDs = new int[booksCount];
    }

    int getBooksCapacity() {
        return booksCount;
    }

    void addNewBooks(const int& newBookIDs) {
        bookIDs = new int(newBookIDs);
    }
};

int main() {
    
    Librarian librarian("Hammad", 3000, 5);

    int fixedBooks[4];
    cout << "Enter IDs for 4 fixed books:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Book " << i+1 << ": ";
        cin >> fixedBooks[i];
    }
    
    librarian.setFixedBooksIDs(fixedBooks);

    librarian.display();

    int newBooksCount;
    cout << "How many new books do you want to add: ";
    cin >> newBooksCount;
    librarian.setBooksCapacity(newBooksCount);

    cout << "Enter IDs for the new books:" << endl;
    for (int i = 0; i < newBooksCount; i++) {
        int newBookID;
        cout << "Book " << i+1 << ": ";
        cin >> newBookID;
        librarian.addNewBooks(newBookID);
    }
    
    return 0;
}
