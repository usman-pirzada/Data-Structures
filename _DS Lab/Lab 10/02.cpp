#include <iostream>
using namespace std;

class AVLTree {
private:
    class AVLNode {
    public:
        int data;
        int height;
        AVLNode* left;
        AVLNode* right;

        AVLNode(int data) : data(data), height(1), left(NULL), right(NULL) {}
    };

    AVLNode* root;

    int height(AVLNode* root) {
        return !root ? 0 : root->height;
    }

    int balanceFactor(AVLNode* root) {
        return !root ? 0 : (height(root->left) - height(root->right));
    }

    int max(const int& a, const int& b) {
        return (a > b) ? a : b;
    }

    AVLNode* leftRotate(AVLNode* root) {
        AVLNode* child = root->right;
        AVLNode* childLeft = child->left;

        child->left = root;
        root->right = childLeft;

        root->height = 1 + max(height(root->left), height(root->right));
        child->height = 1 + max(height(child->left), height(child->right));

        return child;
    }

    AVLNode* rightRotate(AVLNode* root) {
        AVLNode* child = root->left;
        AVLNode* childRight = child->right;

        child->right = root;
        root->left = childRight;

        root->height = 1 + max(height(root->left), height(root->right));
        child->height = 1 + max(height(child->left), height(child->right));

        return child;
    }

    void insertUtil(AVLNode*& root, int data) {
        if(!root) {
            root = new AVLNode(data);
            return;
        }

        if(data < root->data) {
            insertUtil(root->left, data);
        }
        else if(data > root->data) {
            insertUtil(root->right, data);
        }
        else {
            cout << "\nDuplicated values are NOT allowed!!" << endl;
            return;
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balanceFactor(root);

        if(balance > 1) {
            if(data < root->left->data) {
                root = rightRotate(root);
            }
            else if(data > root->left->data) {
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
        }
        else if(balance < -1) {
            if(data > root->right->data) {
                root = leftRotate(root);
            }
            else if(data < root->right->data) {
                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        }
    }

    void inorder(AVLNode* root) {
        if(!root) return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

public:
    AVLTree() : root(NULL) {}

    void insert(int data) {
        insertUtil(root, data);
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    
    AVLTree avlTree;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for(int i=0; i<7; i++) {
        avlTree.insert(arr[i]);
    }

    // Now insert 55
    avlTree.insert(55);

    cout << "Final Tree:\n";
    avlTree.printInorder();
    
    return 0;
}
