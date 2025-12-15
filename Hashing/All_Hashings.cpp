#include <iostream>
using namespace std;

class Node2 {
public:
    string name;
    int key;
    Node2* next;

    Node2() : name(""), key(-1), next(nullptr) {}
    Node2(string name, int key) : name(name), key(key), next(nullptr) {}
};

class Node {
public:
    string name;
    int key;

    Node() : name(""), key(-1) {}
    Node(string name, int key) : name(name), key(key) {}
};

class HashMap {
    Node* hashTable1;   // For closed hashing
    Node2** hashTable2; // For Open Hashing
    int capacity;
    int filledSize;
    int loadFactor;

    int hashFunction(int key) {
        return key % capacity;
    }

    int otherHashFunction(int key) {
        key += key;

        return key%capacity;
    }

public:
    HashMap(int size) : hashTable1(new Node[size]), hashTable2(nullptr), capacity(size), filledSize(0), loadFactor(0) {}
    HashMap(int size, bool chaining) : hashTable1(nullptr), hashTable2(new Node2*[size]{}), capacity(size), filledSize(0), loadFactor(0) {}

    // Closed Hashing
    void linearProbing_insert(int key, string name) {
        int index;
        for(int i=0; i<capacity; i++) {
            index = (i + hashFunction(key)) % capacity;
            if(hashTable1[index].key == -1) {
                hashTable1[index] = Node(name, key);
                return;
            }
        }
        cout << "hashTable1 is full...!\n";
    }

    void quadraticProbing_insert(int key, string name) {
        int index;
        for(int i=0; i<capacity; i++) {
            index = ((i*i) + hashFunction(key)) % capacity;
            if(hashTable1[index].key == -1) {
                hashTable1[index] = Node(name, key);
                return;
            }
        }
        cout << "hashTable1 is full...!\n";
    }

    void doubleHashing_insert(int key, string name) {
        int index;
        for(int i=0; i<capacity; i++) {
            index = (otherHashFunction(key) + i*hashFunction(key)) % capacity;
            if(hashTable1[index].key == -1) {
                hashTable1[index] = Node(name, key);
                return;
            }
        }
        cout << "hashTable1 is full...!\n";
    }

    // Open Hashing
    void chainHashing_insert(int key, string name) {
        int index = hashFunction(key);

        Node2* temp = hashTable2[index];
        while(temp) {
            if(temp->name == name) {
                cout << "The name already exists with same key...!\n";
                return;
            }

            temp = temp->next;
        }

        temp = hashTable2[index];
        hashTable2[index] = new Node2(name, key);
        hashTable2[index]->next = temp;
    }

    void display() {
        if (hashTable1) {
            cout << "\nClosed Hashing Table:\n";
            for (int i = 0; i < capacity; i++) {
                if (hashTable1[i].key != -1)
                    cout << "Index " << i << ": [" << hashTable1[i].key << ", " << hashTable1[i].name << "]\n";
                else
                    cout << "Index " << i << ": --\n";
            }
        }
        if (hashTable2) {
            cout << "\nOpen Hashing Table (Chaining):\n";
            for (int i = 0; i < capacity; i++) {
                cout << "Index " << i << ": ";
                Node2* temp = hashTable2[i];
                while (temp) {
                    cout << "[" << temp->key << ", " << temp->name << "] -> ";
                    temp = temp->next;
                }
                cout << "NULL\n";
            }
        }
    }
};

int main() {
    int size = 7;
    
    // Test Closed Hashing (Linear Probing)
    cout << "=== Linear Probing ===\n";
    HashMap hm1(size);
    hm1.linearProbing_insert(10, "A");
    hm1.linearProbing_insert(20, "B");
    hm1.linearProbing_insert(17, "C"); // Collision with 10 (17%7 = 3, 10%7 = 3)
    hm1.display();

    // Test Closed Hashing (Quadratic Probing)
    cout << "\n=== Quadratic Probing ===\n";
    HashMap hm2(size);
    hm2.quadraticProbing_insert(10, "A");
    hm2.quadraticProbing_insert(20, "B");
    hm2.quadraticProbing_insert(17, "C");
    hm2.display();

    // Test Closed Hashing (Double Hashing)
    cout << "\n=== Double Hashing ===\n";
    HashMap hm3(size);
    hm3.doubleHashing_insert(10, "A");
    hm3.doubleHashing_insert(20, "B");
    hm3.doubleHashing_insert(17, "C");
    hm3.display();

    // Test Open Hashing (Chaining)
    cout << "\n=== Chaining ===\n";
    HashMap hm4(size, true);
    hm4.chainHashing_insert(10, "A");
    hm4.chainHashing_insert(20, "B");
    hm4.chainHashing_insert(17, "C"); // Collision with 10
    hm4.display();
    
    return 0;
}
