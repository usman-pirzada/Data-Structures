#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string data): data(data), next(NULL) {};
};

class SinglyList {
    Node *head, *tail;

public:
    SinglyList(): head(NULL), tail(NULL) {};

    void insertAtFront(string data) {
        Node* newNode = new Node(data);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(string data) {
        Node* newNode = new Node(data);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfterPos(string data, int pos) {
        if(pos == 0) {
            insertAtFront(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* curr = head;
        Node* prev = NULL;

        for (int i = 0; i < pos; i++) {
            if(curr == NULL) {
                cout << "\nInvalid Position!!" << endl;
                delete newNode;
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        prev->next = newNode;
        newNode->next = curr;

        if(curr == NULL) {
            tail = newNode;
        }
    }

    void insertAtPos(string data, int pos) {
        if(pos == 0) {
            cout << "\nInvalid Position\n";
            return;
        }

        if(pos == 1) {
            insertAtFront(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* curr = head;
        Node* prev = NULL;

        for (int i = 1; i < pos; i++) {
            if(curr == NULL) {
                cout << "\nInvalid Position!!" << endl;
                delete newNode;
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        prev->next = newNode;
        newNode->next = curr;

        if(curr == NULL) {
            tail = newNode;
        }
    }

    void insertAfterData(string existingData, string data) {

    }

    void deleteAfterPos() {

    }

    void deleteAtPos() {

    }

    void deleteAfterData() {

    }

    void deleteByValue() {

    }

    void concatenate() {

    }

    int linearSearch() {    // O(n)

    }

    int binarySearch() {    // O(log n)

    }

    int interpolationSearch(int arr[], int low, int high, int key) { // O(n)

        if(key < arr[low] || key > arr[high]) return -1;

        if((high - low) <= 1) {
            if(arr[low] == key) return low;
            else if(arr[high] == key) return high;
            else return -1;
        }

        // Calculate interpolation position
        int pos = low + (((key - arr[low]) *
                    (high - low)) / (arr[high] - arr[low]));

        if(arr[pos] == key) return pos;

        if(arr[pos] < key) return interpolationSearch(arr, pos + 1, high, key);
    
        if(arr[pos] > key) return interpolationSearch(arr, low, pos - 1, key);
    }

    void display() {
        if(head == NULL) {
            cout << "\nEmpty LinkedList" << endl;
            return;
        }

        Node* temp = head;

        while(temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    
    SinglyList sll;
    sll.insertAtFront("Second");
    sll.insertAtFront("First");
    sll.insertAfterPos("FIRST", 1);
    sll.insertAtPos("SECOND", 4);
    sll.display();
    
    return 0;
}
