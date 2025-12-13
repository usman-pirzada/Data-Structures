#include <iostream>
using namespace std;

class MinHeap {
    int* heap;
    int capacity;
    int filledSize;

    void swap(int& a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyDown(int i) {
        int smallest = i;
        int left = 2*i + 1; // Left Child
        int right = 2*i + 2;    // Right Child

        if(left < filledSize && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if(right < filledSize && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if(smallest == i) {
            return;
        }

        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;

        if(i > 0 && heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    MinHeap(int size = 5) : heap(new int[size]), capacity(size), filledSize(0) {}

    void insert(int data) {
        if(filledSize == capacity) {
            cout << "Can't insert. Heap is full...!\n";
            return;
        }

        heap[filledSize] = data;
        heapifyUp(filledSize);
        filledSize++;
    }

    int getMin() {  // It will return top value of the heap after removing it from the heap
        if(filledSize == 0) {
            cout << "Can't get the min value as the heap is empty...!\n";
            return -1;
        }

        int min = heap[0];
        swap(heap[0], heap[filledSize - 1]);
        filledSize--;
        heapifyDown(0);

        return min;
    }

    void print() {
        if(filledSize == 0) {
            cout << "Heap is empty...!\n";
            return;
        }

        for(int i=0; i < filledSize; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    
    MinHeap h;

    h.insert(56);
    h.insert(99);
    h.insert(1);
    h.insert(77);
    h.insert(102);
    h.insert(34);
    h.print();

    cout << h.getMin() << endl;
    h.print();
    
    return 0;
}
