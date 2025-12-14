#include <iostream>
using namespace std;

class Stack {
    int* stack;
    int capacity;
    int front;

public:
    Stack(int size) : stack(new int[size]), capacity(size), front(-1) {}

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (front == capacity - 1);
    }

    void push(int data) {
        if(isFull()) {
            cout << "Can't push. Stack is full...!\n";
            return;
        }

        stack[++front] = data;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Can't pop. Stack is empty...!\n";
            return -1;
        }

        int tmp = stack[front--];

        return tmp;
    }

    
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty...!\n";
            return;
        }

        for (int i = front; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(3);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.print(); 

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    
    s.pop(); 
    
    return 0;
}
