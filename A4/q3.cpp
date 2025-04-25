// Write a C++ Program to reverse a linked list
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *createNode(int data) { // Function to create a new node
    node *n = new node;
    n->data = data;
    n->next = NULL;
    return n; // Returns the pointer pointing to the new node
}

void display(node *head) { // Displays the elements of the linked list
    if (head == NULL) {
        cout << "Linked List is Empty!" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *addNode(node *head, int data) {
    // Function to insert a new node at the end of the linked list
    if (head == NULL) {
        head = createNode(data);
        return head;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(data);
    return head;
}

// Three pointer approach
node *reverse_ll(node *head) { // Function to reverse a linked list
    node *prev = NULL;
    node *curr = head;
    while (curr != NULL) { // Swapping the links
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

// Recursive approach
node *reverse_rec(node *head) { // Function to reverse a linked list
    if (head == NULL || head->next == NULL) {
        return head; // Base condition
    }
    node *new_head = reverse_rec(head->next); // Recursive call
    node *front = head->next;
    front->next = head;
    head->next = NULL;
    return new_head;
}

int main() {
    node *head = NULL;
    head = addNode(head, 55);
    head = addNode(head, 65);
    head = addNode(head, 75);
    head = addNode(head, 88);
    head = addNode(head, 38);
    head = addNode(head, 41);
    cout << "Linked List:" << endl;
    display(head);

    cout << "Reversed Linked List: " << endl;
    head = reverse_rec(head);
    display(head);
}