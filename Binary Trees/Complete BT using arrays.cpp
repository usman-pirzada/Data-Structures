#include <iostream>
using namespace std;

#define treeMaxSize 100

class completeBinaryTree
{
private:
    int *tree;
    int size; // current size based on data inserted yet

public:
    completeBinaryTree() : tree(new int[treeMaxSize]{}), size(0) {}

    bool isFull()
    {
        if (size == treeMaxSize)
        {
            return true;
        }

        return false;
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }

        return false;
    }

    void insert(int value)
    {
        if (isFull())
        {
            cout << "Could not insert! The tree is Full." << endl;
            return;
        }

        tree[size] = value;
        size++;
    }

    void deleteLast()
    {
        if (isEmpty())
        {
            cout << "Could not delete! The tree is Empty." << endl;
            return;
        }

        size--;
    }
};

int main()
{
    completeBinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(30);

    bt.deleteLast();
    bt.insert(40);

    return 0;
}
