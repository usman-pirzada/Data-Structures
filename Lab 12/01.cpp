#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string data) : data(data), next(NULL) {}
};

class HashTable {
    Node** hashtable;
    int tableSize;

    int hashFunction(string key) {
        int ascii = 0;

        for(char ch : key) {
            ascii += ch;
        }

        return ascii % tableSize;
    }

public:
    HashTable() : tableSize(50) {
        hashtable = new Node*[tableSize];
        for(int i=0; i < tableSize; i++) {
            hashtable[i] = NULL;
        }
    }

    void insert(string key, string data) {
        int index = hashFunction(key);

        Node* temp = hashtable[index];
        Node* prev = NULL;

        if(temp == NULL) {
            hashtable[index] = new Node(data);
            cout << "Your value \"" << data << "\" has been stored successfully at table index: " << index << endl;
            return;
        }

        while(temp != NULL) {
            if(temp->data == data) {
                cout << "This value was NOT inserted as its already inserted in the table.";
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        prev->next = new Node(data);
        cout << "Your value \"" << data << "\" has been stored successfully at table index: " << index << endl;
    }
};

int main() {
    
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");
    
    return 0;
}
