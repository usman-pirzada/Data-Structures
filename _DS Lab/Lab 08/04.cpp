#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int size) : arr(new int[size]), front(-1), rear(-1), size(size) {};

    void enqueue(int id)
    {
        if (isFull())
        {
            cout << "Unable to add the patient id. Queue Full!";
            return;
        }

        if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        arr[rear] = id;
    }

    int dequeue()
    {
        int x = 0;

        if (isEmpty())
        {
            cout << "Unable to remove the patient id. Queue is empty!!";
            return -1;
        }
        else if (front == rear)
        {
            x = arr[front];
            front = rear = -1;
        }
        else
        {
            x = arr[front];
            front = (front + 1) % size;
        }

        return x;
    }

    bool isFull()
    {
        if ((rear + 1) % size == front)
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Current Queue: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);

    // Adding patients
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.display();

    // Serving patients
    cout << "Serving patient ID: " << q.dequeue() << endl;
    q.display();

    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106); // Should show "Queue is full!"
    q.display();

    // Serve all patients
    cout << "Serving patient ID: " << q.dequeue() << endl;
    cout << "Serving patient ID: " << q.dequeue() << endl;
    cout << "Serving patient ID: " << q.dequeue() << endl;
    cout << "Serving patient ID: " << q.dequeue() << endl; // Should show "Queue is empty!"
    q.display();

    return 0;
}
