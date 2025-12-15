#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    
    Node(string name) {
        data = name;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    void addStudent(string name) {
        Node* newNode = new Node(name);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        
    }

    void removeStudent(string name) {
        if(!head) {
            cout << "The list is empty!!";
            return;
        }


        Node* temp = new Node();
        while(temp)
    }

    void displayAllStudents() {

    }
};

int main() {
    
    List students;

    students.addStudent("Zeeshan");
    
    return 0;
}
