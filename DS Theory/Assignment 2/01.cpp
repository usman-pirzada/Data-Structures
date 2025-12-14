/*
    Problem:
    A construction company is preparing a temporary emergency bridge across a river. They
    have several rope pieces of different lengths stored in their warehouse. To build the final
    bridge-support rope, they must connect all rope pieces into one single long rope.
    However, the rope-joining machine charges money equal to the sum of lengths of the two ropes
    being connected. To minimize the overall cost, the company must follow an intelligent strategy.
    Using an appropriate data structure, write a C++ program that determines the minimum total cost
    required to connect all the ropes into one rope.
    You are given the following rope lengths:
    Input: arr[] = [4, 2, 7, 6, 9]
    Output: 62
*/
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
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

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
        int p = parent(i);

        if(i > 0 && heap[i] < heap[p]) {
            swap(heap[i], heap[p]);
            heapifyUp(p);
        }
    }

public:
    MinHeap(int size) : heap(new int[size]), capacity(size), filledSize(0) {}

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

    int getFilledSize() {
        return filledSize;
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
    
    MinHeap h(5);

    int arr[] = {4, 2, 7, 6, 9};
    int arr_size = sizeof(arr)/sizeof(int);

    for(int i = 0; i < arr_size; i++) {
        h.insert(arr[i]);
    }

    int total_cost = 0;
    while(h.getFilledSize() > 1) {
        int first = h.getMin();
        int second = h.getMin();
        int cost = first + second;

        total_cost += cost;
        h.insert(cost);
    }

    cout << "Total Cost: " << total_cost << endl;
    
    return 0;
}
