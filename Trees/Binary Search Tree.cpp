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

    static bool searchUtil(Node* root, int key) {
        if(!root) {
            return false;
        }

        if(key == root->data) {
            return true;
        } else if(key < root->data) {
            return searchUtil(root->left, key);
        } else {
            return searchUtil(root->right, key);
        }
    }

    static Node* insertUtil(Node* root, int data) {
        if(!root) {
            return new Node(data);
        }

        if(data < root->data) {
            root->left = insertUtil(root->left, data);
        } else {
            root->right = insertUtil(root->right, data);
        }

        return root;
    }

    static Node* deleteNodeUtil(Node* root, int key) {
        if(!root) {
            return NULL;
        }

        if(key < root->data) {
            root->left = deleteNodeUtil(root->left, key);
        } else if(key > root->data) {
            root->right = deleteNodeUtil(root->right, key);
        } else {
            /**
             * The case when root->left and root->right is NULL is already handled,
             * as in that situation (root->left == NULL) will be true,
             * and root->right (which is also NULL) will be returned.
             */
            if(root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if(root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* inorderSuccessor = root->right;   // Successor of root is the most left node in right subtree
                while(!inorderSuccessor->left) {
                    inorderSuccessor = inorderSuccessor->left;
                }
                root->data = inorderSuccessor->data;
                root->right = deleteNodeUtil(root->right, inorderSuccessor->data);    // delete the duplicate (as we have copied its data to root)
            }
        }

        return root;
    }

    static void displayInorderUtil(Node* root) {
        if(!root) {
            return;
        }

        displayInorderUtil(root->left);
        cout << root->data << " ";
        displayInorderUtil(root->right);
    }

public:
    BST() : root(NULL) {}

    bool search(int key) {
        return searchUtil(root, key);
    }

    void insert(int data) {
        root = insertUtil(root, data);
    }

    void deleteNode(int key) {
        root = deleteNodeUtil(root, key);
    }

    void displayInorder() {
        displayInorderUtil(root);
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
