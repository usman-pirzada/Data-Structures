/**
 * The method in which a node’s height is initialized to 0 (edges counted)
 * is called the edge-based height or 0-based height convention.
 * Theoretically, we count the number of edges below a node
 * on its right or left (longest path) to determine its balance factor.
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

        AVLNode(int data) : data(data), height(0), left(NULL), right(NULL) {}
    };

    AVLNode* root;

    int height(AVLNode* root) {
        // Returns -1 when the passed node doesn't exist, so that leaf node height becomes 1 + max(-1, -1) = 0.
        return !root ? -1 : root->height;
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
        // Sequence matters here. root (now child) must be updated before child (now root) because child's height depends on root's new height.
        root->height = 1 + max(height(root->left), height(root->right));
        child->height = 1 + max(height(child->left), height(child->right));

        return child;   // Now child is the new root
    }

    AVLNode* rightRotate(AVLNode* root) {
        AVLNode* child = root->left;
        AVLNode* childRight = child->right;

        // Put root in child's right, then put childRight (node at child's right before attaching root to child's left) in root's left.
        child->right = root;
        root->left = childRight;

        // Update heights of root & child
        // Sequence matters here. root (now child) must be updated before child (now root) because child's height depends on root's new height.
        root->height = 1 + max(height(root->left), height(root->right));
        child->height = 1 + max(height(child->left), height(child->right));

        return child;   // Now child is the new root
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

    void deleteUtil(AVLNode*& root, int data) {
        if(!root) {
            return;
        }

        if(data < root->data) {
            deleteUtil(root->left, data);
        }
        else if(data > root->data) {
            deleteUtil(root->right, data);
        }
        else {  // If (data == root->data)
            // When the node (to be deleted) is Leaf Node (has NO child)
            if(!root->left && !root->right) {
                delete root;
                root = NULL;
            }

            // When the node has only one child
            else if(root->left && !root->right) {
                AVLNode* temp = root->left;
                delete root;
                root = temp;
            }
            else if(!root->left && root->right) {
                AVLNode* temp = root->right;
                delete root;
                root = temp;
            }

            // When the node has both child
            else if(root->left && root->right) {
                // "curr" pointer will be used to traverse in the root's right sub-tree to find min element (which will be the left-most node)
                AVLNode* curr = root->right;
                while(curr->left) {
                    curr = curr->left;
                }

                root->data = curr->data;
                deleteUtil(root->right, curr->data);
            }
        }

        if(!root) return;   // Required here since the last remaining Node might have been deleted.

        root->height = 1 + max(height(root->left), height(root->right));

        // *** Self-balancing Logic ***

        int balance = balanceFactor(root);

        // Left side case
        if(balance > 1) {
            // Left-Right unbalancing
            if(balanceFactor(root->left) < 0) {  // When for root->left, leftHeight < rightHeight
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
            // Left-Left unbalancing
            else {    // When for root->left, leftHeight > rightHeight or both equal
                root = rightRotate(root);
            }
        }

        // Right side case
        else if(balance < -1) {
            // Right-Left unbalancing
            if(balanceFactor(root->right) > 0) {
                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
            // Right-Right unbalancing
            else {
                root = leftRotate(root);
            }
        }
    }

    /*
    AVLNode* deleteUtil(AVLNode* root, int data) {
        if(!root) {
            return NULL;
        }

        if(data < root->data) {
            root->left = deleteUtil(root->left, data);
        }
        else if(data > root->data) {
            root->right = deleteUtil(root->right, data);
        }
        else {  // If (data == root->data)
            // When the node (to be deleted) is Leaf Node (has NO child)
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            }

            // When the node has only one child
            else if(root->left && !root->right) {
                AVLNode* temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->left && root->right) {
                AVLNode* temp = root->right;
                delete root;
                return temp;
            }

            // When the node has both child
            else if(root->left && root->right) {
                // "curr" pointer will be used to traverse in the root's right sub-tree to find min element (which will be the left-most node)
                AVLNode* curr = root->right;
                while(curr->left) {
                    curr = curr->left;
                }

                root->data = curr->data;
                root->right = deleteUtil(root->right, curr->data);
            }
        }

        root->height = 1 + max(height(root->left), height(root->right));

        // *** Self-balancing Logic ***

        int balance = balanceFactor(root);

        // Left side case
        if(balance > 1) {
            // Left-Left unbalancing
            if(balanceFactor(root->left) >= 0) {    // When for root->left, leftHeight > rightHeight or both equal
                root = rightRotate(root);
            }
            // Left-Right unbalancing
            else {  // When for root->left, rightHeight > leftHeight
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
        }

        // Right side case
        else if(balance < -1) {
            // Right-Right unbalancing
            if(balanceFactor(root->right) <= 0) {
                root = leftRotate(root);
            }
            // Right-Left unbalancing
            else {
                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        }

        return root;
    }
    */

    /*
    AVLNode* insertUtil(AVLNode* root, int data) {
        if(!root) {
            return (new AVLNode(data));
        }

        if(data < root->data) {
            insertUtil(root->left, data);
        }
        else if(data > root->data) {
            insertUtil(root->right, data);
        }
        else {
            cout << "\nDuplicated values are NOT allowed!!" << endl;
            return root; // No insertion for duplicates.
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
        /*
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

        return root;
    }
    */

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
        
        /*
        root = insertUtil(root, data);
        */
    }

    void deleteNode(int data) {
        deleteUtil(root, data);

        /*
        root = deleteUtil(root, data);
        */
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

    avlTree.deleteNode(25);

    avlTree.printInorder();
    
    return 0;
}
