#include <iostream>
using namespace std;

class MaxHeap {
    int* heap;
    int capacity;
    int filledSize;

    void swap(int& a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Returns the index of parent
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Returns the index of left child
    int leftChild(int i) {
        return (2*i + 1);
    }

    // Returns the index of right child
    int rightChild(int i) {
        return (2*i + 2);
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if(left < filledSize && heap[left] > heap[largest]) {
            largest = left;
        }

        if(right < filledSize && heap[right] > heap[largest]) {
            largest = right;
        }

        if(largest == i) {
            return;
        }

        swap(heap[i], heap[largest]);
        heapifyDown(largest);
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;

        if(i > 0 && heap[i] > heap[parent]) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    MaxHeap(int size = 5) : heap(new int[size]), capacity(size), filledSize(0) {}

    void insert(int data) {
        if(filledSize == capacity) {
            cout << "Can't insert. Heap is full...!\n";
            return;
        }

        heap[filledSize] = data;
        heapifyUp(filledSize);
        filledSize++;
    }

    int getMax() {  // It will return top value of the heap after removing it from the heap
        if(filledSize == 0) {
            cout << "Can't get the max value as the heap is empty...!\n";
            return -1;
        }

        int max = heap[0];
        swap(heap[0], heap[filledSize - 1]);
        filledSize--;
        heapifyDown(0);

        return max;
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
    
    MaxHeap h;

    h.insert(56);
    h.insert(99);
    h.insert(1);
    h.insert(77);
    h.insert(102);
    h.insert(34);
    h.print();

    cout << h.getMax() << endl;
    h.print();
    
    return 0;
}
