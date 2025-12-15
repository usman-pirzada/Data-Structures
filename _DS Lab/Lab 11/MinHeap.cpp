#include <iostream>
using namespace std;

class Heap {
    int* heap;
    int size;
    int capacity;

public:
    Heap(int capacity) : heap(new int[capacity]), size(0), capacity(capacity) {};

    bool isEmpty() {
        if(size == 0) {
            return true;
        }

        return false;
    }

    bool isFull() {
        if(size == capacity) {
            return true;
        }

        return false;
    }

    int parent(int i) {
        return (i - 1)/2;
    }

    int leftChild(int i) {
        return (2 * i) + 1;
    }

    int rightChild(int i) {
        return (2 * i) + 2;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void minHeapify(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if(left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if(right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if(smallest != i) {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }

    void insert(int val) {
        if(isFull()) {
            cout << "Heap is Full!" << endl;
            return;
        }

        heap[size++] = val; // Incrementing size after assigning val to heap[size]

        int i = size - 1;   // size is NOT modified here

        while(i > 0 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
};

int main() {
    
    Heap heap(3);
    
    
    return 0;
}
