//Q2. Program to implement Binary Search Tree
#include <iostream>
#include <stack> // Includes Stack library from C++ STL
using namespace std;

class TreeNode { // Class for a node in BST
  public:
    int data;
    TreeNode *left, *right;

    TreeNode(int val) { // Constructor
        data = val;
        left = right = NULL;
    }

    TreeNode(int val, TreeNode *left, TreeNode *right) { // Constructor
        data = val;
        this->left = left;
        this->right = left;
    }
};

// Structure to store the both parent and child Node
struct NodeInfo {
    TreeNode *parent, *child;
};

class BST { // Class for the BST
  public:
    TreeNode *root; // Root Node

    BST() { // Constructor
        root = NULL;
    }

    BST(TreeNode *node) { // Constructor
        root = node;
    }

    // To search a node in a BST and return the address of its parent and itself
    NodeInfo searchBST(int key) {
        TreeNode *parent = NULL; // Keeps track of parent child
        TreeNode *child = root;  // Keeps track of chid node
        NodeInfo info;           // Stores the addresses of both parent and child node

        while (child != NULL) {
            if (child->data == key) {
                // Found the key node
                break;
            } else if (child->data < key) {
                parent = child;
                child = child->right;
                // Go to right sub-tree
            } else {
                parent = child;
                child = child->left;
                // Go to left sub-tree
            }
        }
        info.parent = parent;
        info.child = child;
        return info;
    }

    // To insert a new Node in the BST
    void insertBST(int key) {
        TreeNode *newNode = new TreeNode(key);
        if (root == NULL) { // Empty BST
            root = newNode;
            return;
        }

        NodeInfo info = searchBST(key);

        if (info.child != NULL) {
            // In case of duplicate keys, Do Nothing
            return;
        }
        // Inserting the new Node to its parent
        if (info.parent->data > key) {
            info.parent->left = newNode;
        } else {
            info.parent->right = newNode;
        }
        cout << "Inserted " << key << " into the BST." << endl;
    }

    // Display of BST using InOrder Traversal (Recursive)
    void displayInOrderRec(TreeNode *rootNode) {
        if (rootNode == NULL) {
            return;
        }
        displayInOrderRec(rootNode->left); // Recursive call for left sub-tree
        cout << rootNode->data << " ";
        displayInOrderRec(rootNode->right); // Recursive call for right sub-tree
    }

    // Display of BST using InOrder Traversal (Non-Recursive/ Iterative)
    void displayInOrder() {
        // Using stack Data Structure
        stack<TreeNode *> st;  // Stack to store TreeNode pointers
        TreeNode *node = root; // Temporary TreeNode pointer

        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left; // Go to left sub-tree
            } else {
                if (st.empty()) {
                    break;
                }
                node = st.top();
                st.pop();
                cout << node->data << " ";
                node = node->right; // Go to right sub-tree
            }
        }
    }

    // To delete a node with a given key (recursive)
    TreeNode *deleteBST(int key) {
        if (root == nullptr) {
            return root;
        }

        NodeInfo info = searchBST(key);
        TreeNode *parent = info.parent;
        TreeNode *current = info.child;

        // If the key is not found, return the original root
        if (current == nullptr) {
            cout << "Key not found!" << endl;
            return root;
        }

        // Case 1: Node with only one child or no child
        if (current->left == nullptr || current->right == nullptr) {
            TreeNode *temp = (current->left != nullptr) ? current->left : current->right;

            if (parent == nullptr) {
                // If node to be deleted is the root node
                root = temp;
            } else if (parent->left == current) {
                parent->left = temp;
            } else {
                parent->right = temp;
            }
            delete current;
        }
        // Case 2: Node with two children
        else {
            // Find the inOrder successor (smallest node in the right subtree) iteratively
            TreeNode *successorParent = current;
            TreeNode *successor = current->right;
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }

            // Copy the inOrder successor's value to the current node
            current->data = successor->data;

            // Now we need to delete the successor
            if (successorParent == current) {
                // If the successor is the right child of the current node
                current->right = successor->right;
            } else {
                // If the successor is not the right child of the current node
                successorParent->left = successor->right;
            }
            delete successor;
        }

        return root;
    }
};

int main() {
    BST *tree = new BST;
    tree->insertBST(50);
    tree->insertBST(20);
    tree->insertBST(16);
    tree->insertBST(79);
    tree->insertBST(24);
    tree->insertBST(83);
    tree->displayInOrder();
    tree->deleteBST(24);
    tree->deleteBST(24);
    tree->deleteBST(16);
    tree->deleteBST(50);
    tree->displayInOrder();
    return 0;
}