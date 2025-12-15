#include <iostream>
using namespace std;

class Document {
    string* content;

public:
    Document(string content) {  // Parameterized Constructor
        this->content = new string(content);
    }

    Document(const Document& doc) { // Copy Constructor
        // doc is not a pointer - it's a reference to a Document object (note the & in const Document& doc)

        content = new string(*doc.content); // doc.content is a pointer - it's a string* member inside the Document class
    }

    Document& operator=(const Document& otherDoc) { // Copy Operator Assignment
        if(this == &otherDoc) return *this;

        delete content;
        content = new string(*otherDoc.content);

        return *this;
    }

    ~Document() {   // Destructor
        delete content;
        content = nullptr;
    }

    void modifyContent(const string& newContent) {
        *content = newContent;
    }

    void displayContent() {
        cout << "\n" << *content << endl;
    }
};

int main() {
    
    Document doc1("This is my first document");
    doc1.displayContent();

    Document doc2 = doc1;
    doc2.displayContent();

    Document doc3("This is the 2nd document");
    doc3.displayContent();

    doc2 = doc3;
    doc2.displayContent();

    doc1.modifyContent("Modifying the content of 1st document.");

    doc1.displayContent();
    doc2.displayContent();
    doc3.displayContent();
    
    return 0;
}
