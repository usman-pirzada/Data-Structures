#include <iostream>
using namespace std;

class LinearQueue {
    int* queue;
    int capacity;
    int front;  // Removal is done on front
    int rear;   // Insertion is done on rear

public:
    LinearQueue(int size) : queue(new int[size]), capacity(size), front(-1), rear(-1) {}

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == capacity - 1);
    }

    void enqueue(int data) {
        if(isFull()) {
            cout << "Can't Insert. The queue is full...!\n";
            return;
        }

        if(front == -1) front = 0;
        queue[++rear] = data;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Can't dequeue. The queue is empty...!\n";
            return -1;
        }

        int tmp = queue[front++];
        
        // Reset pointers if queue becomes empty to reuse space
        if(front > rear) {
            front = rear = -1;
        }
        return tmp;
    }

    void print() {
        if(isEmpty()) {
            cout << "Queue is empty...!\n";
            return;
        }
        for(int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    LinearQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();

    q.dequeue();
    q.print();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.print();

    return 0;
}
