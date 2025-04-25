//Q1. Program to implement a Tree
#include <iostream>
using namespace std;

// Constants for tree limits
const int MAX_CHILDREN = 10; // Maximum number of children per node
const int MAX_NODES = 100;   // Maximum number of nodes in the tree

// Node structure for the general tree
struct TreeNode {
    int data;
    TreeNode *children[MAX_CHILDREN]; // Array to hold the children of the node
    int childCount;                   // To track the number of children

    TreeNode(int value) : data(value), childCount(0) {
        // Initialize the children array to nullptr
        for (int i = 0; i < MAX_CHILDREN; i++) {
            children[i] = nullptr;
        }
    }
};

// General tree class to manage tree operations
class GeneralTree {
  public:
    TreeNode *nodes[MAX_NODES]; // Array to hold all nodes in the tree
    int nodeCount;              // To track the number of nodes in the tree

    GeneralTree(int rootValue) {
        // Create the root node and add it to the nodes array
        nodes[0] = new TreeNode(rootValue);
        nodeCount = 1;
    }

    // Function to add a child to a specific node
    void addChild(int parentValue, int childValue) {
        TreeNode *parentNode = findNode(parentValue);
        if (parentNode != nullptr) {
            if (parentNode->childCount < MAX_CHILDREN) {
                parentNode->children[parentNode->childCount] = new TreeNode(childValue);
                parentNode->childCount++;
                nodes[nodeCount++] = parentNode->children[parentNode->childCount - 1];
                // Add the child to nodes array
                cout << "Added node with value " << childValue << " as a child of node " << parentValue << endl;
            } else {
                cout << "Parent node " << parentValue << " cannot have more than " << MAX_CHILDREN << " children!" << endl;
            }
        } else {
            cout << "Parent node with value " << parentValue << " not found!" << endl;
        }
    }

    // Function to find a node with a specific value (iterative)
    TreeNode *findNode(int value) {
        for (int i = 0; i < nodeCount; i++) {
            if (nodes[i]->data == value) {
                return nodes[i];
            }
        }
        return nullptr;
    }

    // Function to display the tree in level order using a manual queue
    void displayLevelOrder() {
        if (nodeCount == 0)
            return;

        // Manually implementing a queue using an array
        TreeNode *queue[MAX_NODES];
        int front = 0, rear = 0;

        // Enqueue the root node
        queue[rear++] = nodes[0]; // Root is at nodes[0]

        while (front < rear) {
            int levelSize = rear - front;

            for (int i = 0; i < levelSize; i++) {
                // Dequeue the front node
                TreeNode *currentNode = queue[front++];

                // Print the current node
                cout << currentNode->data << " ";

                // Enqueue all children of the current node
                for (int j = 0; j < currentNode->childCount; j++) {
                    queue[rear++] = currentNode->children[j];
                }
            }
            cout << endl; // New line after each level
        }
    }
};

int main() {
    // Create a general tree with the root node having value 1
    GeneralTree tree(1);

    // Add children to specific nodes
    tree.addChild(1, 2);
    tree.addChild(1, 3);
    tree.addChild(2, 4);
    tree.addChild(2, 5);
    tree.addChild(3, 6);
    tree.addChild(3, 7);

    // Display the tree in level order
    cout << "Tree in level order:" << endl;
    tree.displayLevelOrder();

    return 0;
}