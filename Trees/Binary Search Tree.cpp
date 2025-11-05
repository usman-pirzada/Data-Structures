#include <iostream>
using namespace std;

class BST {
private:
    class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) : data(data), left(NULL), right(NULL) {}
    };

    Node* root;

    static bool searchHelper(Node* root, int key) {
        if(!root) {
            return false;
        }

        if(key == root->data) {
            return true;
        } else if(key < root->data) {
            return searchHelper(root->left, key);
        } else {
            return searchHelper(root->right, key);
        }
    }

    static Node* insertHelper(Node* root, int data) {
        if(!root) {
            return new Node(data);
        }

        if(data < root->data) {
            root->left = insertHelper(root->left, data);
        } else {
            root->right = insertHelper(root->right, data);
        }

        return root;
    }

    static Node* getInorderSuccessor(Node* root) {
        while(root && root->left) {
            root = root->left;
        }
        return root;
    }

    static Node* deleteNodeHelper(Node* root, int key) {
        if(!root) {
            return NULL;
        }

        if(key < root->data) {
            root->left = deleteNodeHelper(root->left, key);
        } else if(key > root->data) {
            root->right = deleteNodeHelper(root->right, key);
        } else {
            if(root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if(root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* inorderSuccessor = getInorderSuccessor(root->right);
                root->data = inorderSuccessor->data;
                root->right = deleteNodeHelper(root->right, inorderSuccessor->data);    // delete the duplicate (as we have copied its data to root)
            }
        }

        return root;
    }

    static void displayInorderHelper(Node* root) {
        if(!root) {
            return;
        }

        displayInorderHelper(root->left);
        cout << root->data << " ";
        displayInorderHelper(root->right);
    }

public:
    BST() : root(NULL) {}

    bool search(int key) {
        return searchHelper(root, key);
    }

    void insert(int data) {
        root = insertHelper(root, data);
    }

    void deleteNode(int key) {
        root = deleteNodeHelper(root, key);
    }

    void displayInorder() {
        displayInorderHelper(root);
    }
};

int main() {
    
    BST myBST;
    myBST.insert(3);
    myBST.insert(2);
    myBST.insert(1);
    myBST.insert(5);
    myBST.insert(6);
    myBST.insert(4);
    myBST.displayInorder();

    myBST.deleteNode(6);
    cout << endl;
    myBST.displayInorder();

    cout << endl;
    cout << myBST.search(76);
    
    return 0;
}
