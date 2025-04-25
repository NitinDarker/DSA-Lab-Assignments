// Write a C++ Program to find the middle element of the linked list
#include <iostream>
using namespace std;

struct node { // Structure for a node in a linked list
    int data;
    node *next;
};

node *createNode(int data) { // To create a new node structure
    node *n = new node;
    n->data = data;
    n->next = NULL;
    return n; // Returns the pointer pointing this newly created node
}

void display(node *head) { // To print the data in a linked list
    if (head == NULL) {
        cout << "Linked List is Empty!" << endl;
        return;
    }
    node *temp = head; // Creating a temporary pointer
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next; // Traversing the temp till the last node of the list
    }
    cout << endl;
}

node *addNode(node *head, int data) { // To insert a new node in the list
    if (head == NULL) {
        head = createNode(data); // If the list is empty, then creates first node
        return head;
    }

    node *temp = head; // Creating a temporary pointer to a node
    while (temp->next != NULL) {
        temp = temp->next;
    } // Temp points to the last node of the linked list

    temp->next = createNode(data); // Linking last node to the newly created node
    return head;
}

int middle_node(node *head) {
    // Func to find the middle node of the linked list
    node *slow = head;
    node *fast = head; // Temporary pointers - slow & fast
    // slow moves 1 step while fast moves 2 steps
    // Odd nodes - When fast reaches null, slow points to middle node
    // Even nodes - When fast reaches last node, slow points to second middle node

    int firstMiddle = 0; // In case of even nodes in list
    while (fast != NULL && fast->next != NULL) {
        if (fast->next->next == NULL) {
            firstMiddle = slow->data;
        }
        slow = slow->next;       // Slow moves 1 step
        fast = fast->next->next; // Fast moves 2 steps
    }
    if (firstMiddle == 0) { // For odd no. of nodes in the list
        return slow->data; 
    } else {
        return (firstMiddle + slow->data) / 2;
        // In case of even nodes, return the average of both middles
    }
}

int main() {
    // Head points to the first node of the linked list
    node *head = NULL; // Initially head points to NULL
    // An empty linked list is created...
    head = createNode(10);
    head = addNode(head, 25);
    head = addNode(head, 35);
    head = addNode(head, 45);
    head = addNode(head, 55);
    head = addNode(head, 65);
    head = addNode(head, 85);

    display(head);
    cout << "Middle Element: " << middle_node(head) << endl;
}