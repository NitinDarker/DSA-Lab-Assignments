#include <iostream>
using namespace std;

struct dNode { // Structure for a node in doubly linked list
    int data;
    dNode *prev; // Points to previous node
    dNode *next; // Points to next node
} typedef node;

struct dll {     // Structure for a doubly linked list
    node *front; // Stores the address of first node of the list
    node *rear;  // Stores the address of last node of the list
};

node *createNode(int data) { // Func to create a new node
    node *n = new node;
    n->next = NULL;
    n->prev = NULL;
    n->data = data;
    return n; // Returns a pointer pointing to newly created node
}

dll createDLL() { // Func to create a new doubly linked list
    dll list;
    list.front = NULL;
    list.rear = NULL;
    return list; // Returns an empty linked list
}

void updateDLL(dll &list, node *front, node *rear) {
    // Updates the front and rear pointers of the doubly linked list
    list.front = front;
    list.rear = rear;
}

bool isEmpty(dll &list) { // Func to check if the list is empty or not
    if (list.front == NULL) {
        return true;
    }
    return false;
}

dll insert_at_end(dll &list, int data) { // Func to insert a new node at the end
    if (isEmpty(list)) {
        node *n = createNode(data);
        updateDLL(list, n, n);
        return list;
    }
    node *n = createNode(data);  // Creating a new node
    list.rear->next = n;         // Linking next of rear to new node
    n->prev = list.rear;         // Linking prev of new node to rear
    list.rear = list.rear->next; // Updating the rear
    return list;                 // Returning the list
}

dll insert_at_start(dll &l, int data) { // Func to insert a new node at the start
    if (isEmpty(l)) {
        node *n = createNode(data);
        updateDLL(l, n, n);
        return l;
    }
    node *n = createNode(data); // Creating a new node
    l.front->prev = n;          // Linking prev of front to new node
    n->next = l.front;          // Linking next of new node to front
    l.front = n;                // Updating the front
    return l;                   // Returning the list
}

dll insert_at_sorted(dll &l, int data) { // Func to insert a new node in a sorted order
    if (isEmpty(l)) {
        // If doubly linked list is empty
        node *n = createNode(data);
        updateDLL(l, n, n);
        return l;
    }
    if (l.front == l.rear) {
        // Only one node is present in doubly linked list
        if (l.front->data > data) {
            l = insert_at_start(l, data);
            return l;
        } else {
            l = insert_at_end(l, data);
            return l;
        }
    }
    // If more than one node is present
    if (data < l.front->data) {
        insert_at_start(l, data);
        return l;
    }
    node *n = createNode(data);
    node *temp = l.front;

    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    } // Temp points to the node after which a new node is to be inserted
    n->next = temp->next; // Linking the next of new node to temp->next
    n->prev = temp;       // Linking the prev of new node to temp
    temp->next = n;       // Linking the next of temp to new node
    if (n->next != NULL) {
        n->next->prev = n;
    }
    return l;
}

void display(dll &list) { // Func to display the elements of the list
    if (isEmpty(list)) {
        cout << "Doubly Linked list is Empty!" << endl;
        return;
    }
    node *temp = list.front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

dll reverse(dll &l) { // Func to reverse the doubly linked list
    if (l.front == l.rear || l.front == NULL) {
        // In case of only one node or empty list
        return l;
    }
    node *temp = l.front;
    while (temp != nullptr) {
        node *tempNext = temp->next;
        swap(temp->prev, temp->next);
        if (tempNext == NULL) {
            break;
        }
        temp = tempNext;
    }
    swap(l.front, l.rear);
    return l;
}

int search(dll &l, int key) { // Func to search an element in the linked list
    node *temp = l.front;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    cout << "Element not found!" << endl;
    return -1;
}

int main() {
    dll list = createDLL();
    list = insert_at_end(list, 5);
    list = insert_at_end(list, 15);
    list = insert_at_end(list, 25);
    list = insert_at_end(list, 35);
    list = insert_at_end(list, 45);
    list = insert_at_end(list, 55);

    display(list);
    list = reverse(list);
    display(list);
    cout << "Input an element to find: ";
    int ele;
    cin >> ele;
    cout << "Position: " << search(list, ele) << endl;
}