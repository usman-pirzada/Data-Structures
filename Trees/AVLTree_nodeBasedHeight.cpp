/**
 * The method in which a node’s height is initialized to 1 (not zero)
    is called the node-based height or 1-based height convention.
 * Theoretically, we count the number of nodes (NOT edges) below a node
    on its right or left to determine its balance factor.
 */

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
        // Returns 0 when the passed node doesn't exist, as for Node-based height single Node's height is 1.
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

        // Put root in child's left, then put childLeft (node at child's left before attaching root to child's left) in root's right.
        child->left = root;
        root->right = childLeft;

        // Update heights of root & child
        root->height = 1 + max(height(root->left), height(root->right));
        child->height = 1 + max(height(child->left), height(child->right));

        return child;
    }

    AVLNode* rightRotate(AVLNode* root) {
        AVLNode* child = root->left;
        AVLNode* childRight = child->right;

        // Put root in child's right, then put childRight (node at child's right before attaching root to child's left) in root's left.
        child->right = root;
        root->left = childRight;

        // Update heights of root & child
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
            return; // No insertion for duplicates.
        }

        root->height = 1 + max(height(root->left), height(root->right));

        // *** Self-balancing Logic ***

        int balance = balanceFactor(root);

        /**
         * Safe to access root->left->data / root->right->data here: the balance
           factor is checked first, so the corresponding child must exist
           (balance > 1 implies root->left != nullptr; balance < -1 implies root->right != nullptr).
         */
        // Left-heavy subtree
        if(balance > 1) {
            // Left-Left unbalanced
            if(data < root->left->data) {
                root = rightRotate(root);
            }
            // Left-Right unbalanced
            else if(data > root->left->data) {
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
        }

        // Right-heavy subtree
        else if(balance < -1) {
            // Right-Right unbalanced
            if(data > root->right->data) {
                root = leftRotate(root);
            }
            // Right-Left unbalanced
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

    avlTree.insert(30);
    avlTree.insert(20);
    avlTree.insert(40);
    avlTree.insert(10);
    avlTree.insert(25);
    avlTree.insert(35);
    avlTree.insert(50);

    avlTree.printInorder();
    
    return 0;
}
