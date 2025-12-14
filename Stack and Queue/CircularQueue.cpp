/*
 * In the current logic, 'front' always points directly to the valid data waiting to be dequeued
 * and 'rear' always points directly to the last valid data inserted.
 * And when queue empty, both 'front' and 'rear' point to -1
 * Here, rear == front means that the queue has exactly one element
*/
#include <iostream>
using namespace std;

class CircularQueue {
    int* queue;
    int capacity;
    int front;  // Removal is done on front
    int rear;   // Insertion is done on rear

public:
    CircularQueue(int size) : queue(new int[size]), capacity(size), front(-1), rear(-1) {}  // If use front = rear = 0, then we will need always an empty slot in queue to diff b/w full & empty queue

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

    void enqueue(int data) {
        if(isFull()) {
            cout << "Can't Insert. The queue is full...!\n";
            return;
        }

        if(isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % capacity;

        queue[rear] = data;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Can't dequeue. The queue is empty...!\n";
            return -1;
        }

        int tmp = queue[front];

        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;

        return tmp;
    }

    void print() {
        if(isEmpty()) {
            cout << "Queue is empty...!\n";
            return;
        }
        
        int i = front;
        while(true) {
            cout << queue[i] << " ";
            if(i == rear) break; // Stop after printing the rear element
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

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
