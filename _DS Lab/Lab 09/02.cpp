#include <iostream>
#include <stack>
using namespace std;

class BST {
public:
    class Node {
    public:
        int id;
        string name;

        Node* left;
        Node* right;
    
        Node(int id, string name) : id(id), name(name), right(nullptr), left(nullptr) {};
    };

    Node* root;
    stack<BST::Node*> myStack;

    void preorder(Node* rootNode) {
        if(rootNode == NULL) return;

        myStack.push(rootNode);
        preorder(rootNode->left);
        preorder(rootNode->right);
    }

    void inorder(Node* rootNode) {
        if(rootNode == NULL) return;

        inorder(rootNode->left);
        myStack.push(rootNode);
        inorder(rootNode->right);
    }

    void postorder(Node* rootNode) {
        if(rootNode == NULL) return;

        postorder(rootNode->left);
        postorder(rootNode->right);
        myStack.push(rootNode);
    }

    BST() : root(nullptr) {};
    bool insert(int id, string name) {
        Node* newNode = new Node(id, name);

        if(root == NULL) {
            root = newNode;
            return true;
        }

        Node* temp = root;
        while(temp != NULL) {
            if(newNode->id == temp->id) {
                return false;
            } else if(newNode->id < temp->id && temp->left == NULL) {
                temp->left = newNode;
                return true;

            } else if(newNode->id < temp->id) {
                temp = temp->left;

            } else if(newNode->id > temp->id && temp->right == NULL) {
                temp->right = newNode;
                return true;

            } else if(newNode->id > temp->id) {
                temp = temp->right;
            }
        }

        return true;
    }

    void traverse_and_display() {
        preorder(this->root);
        inorder(this->root);
        postorder(this->root);

        cout << "Now stack output:\n";
        while(myStack.top() != NULL) {
            Node* temp = myStack.top();
            cout << "ID: " << temp->id << "Name: " << temp->name << endl;
            myStack.pop();
        }
    }
};

int main() {

    BST customers;

    customers.insert(1001, "Imran");
    customers.insert(2002, "Kamran");
    customers.insert(3003, "Rizwan");
    customers.insert(4004, "Ali");
    customers.insert(5005, "Hamza");

    customers.traverse_and_display();


    return 0;
}
