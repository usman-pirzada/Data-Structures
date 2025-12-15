#include <iostream>
using namespace std;

class BST {
private:
    class Node {
    public:
        int id;
        int quantity;

        Node* left;
        Node* right;
    
        Node(int id, int quantity) : id(id), quantity(quantity), right(nullptr), left(nullptr) {};
    };

    Node* root;

    bool editingUtility(Node* root, int id, int quantity) {
        if(root == NULL) return false;

        if(root->id == id) {
            root->quantity = quantity;
            cout << "Quantity of product having id \"" << id << "\" have been updated!!";
            return true;
        }
        if(editingUtility(root->left, id, quantity)) return true;
        if(editingUtility(root->right, id, quantity)) return true;

        return false;
    }

    void preorder(Node* rootNode) {
        if(rootNode == NULL) return;

        cout << "ID: " << rootNode->id << ", Quantity: " << rootNode->quantity << endl;
        preorder(rootNode->left);
        preorder(rootNode->right);
    }

public:
    BST() : root(nullptr) {};

    bool insert(int id, int quantity) {
        Node* newNode = new Node(id, quantity);

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

    void editQuantity(int id, int newQuantity) {
        if(!editingUtility(this->root, id, newQuantity)) {
            cout << "Product with id \"" << id << "\" not found!!\n";
        }
    }
    void display() {
        preorder(this->root);
    }
};

int main() {

    BST inventory;

    inventory.insert(1001, 10);
    inventory.insert(2002, 20);
    inventory.insert(3003, 30);
    inventory.display();

    inventory.editQuantity(2002, 50);

    cout << "\n\n";

    inventory.display();

    return 0;
}
