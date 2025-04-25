#include <iostream>
using namespace std;

struct node { // Structure for a node in a linked list
    int data;
    node *next;
};

node *createNode(int data) { // To create a new node
    node *n = new node;
    n->data = data;
    return n; // Returns the pointer pointing this newly created node
}

bool isEmpty(node *head) { // To check if a linked list is empty or not
    if (head == NULL) {    // Head points to the first node in the list
        return true;
    }
    return false;
}

node *insert_at_end(node *head, int data) { // To insert an element at the end of the list
    if (isEmpty(head)) {
        // Case where linked list empty
        head = createNode(data);
        return head;
    }
    node *temp = head; // Creating a new temporary pointer

    while (temp->next != NULL) {
        temp = temp->next;
        // Temp now points to the last node of the linked list
    }
    temp->next = createNode(data); // Linking last node to new node in the list
    return head;
}

node *insert_at_beg(node *head, int data) { // To insert an element at the beginning of the list
    if (isEmpty(head)) {
        // Case where linked list is empty
        head = createNode(data);
        return head;
    }
    node *n = createNode(data);
    n->next = head; // Linking new node to the head of the list
    head = n;       // This new node is the head of the list now
    return head;
}

node *insert_at_sorted(node *head, int data) { // To insert an element in sorted order
    if (isEmpty(head)) {
        // Case where linked list is empty
        head = createNode(data);
        return head;
    }
    node *n = createNode(data);

    node *ptr = head; // Creating a temporary pointer

    if (ptr->next == NULL) {
        // Case where there is only one element/node in a linked list
        if (ptr->data <= data) {
            ptr->next = n; // Inserting new node at the end
        } else {
            n->next = ptr; // Inserting new node at the beginning
            head = n;
        }
        return head;
    }

    // Assuming the list is already sorted, Inserting an element to not disturb its order
    while (ptr->next != NULL) {
        // Case where there is more than one element/node in the list
        if (ptr->next->data > data) {
            break;
        }
        ptr = ptr->next;
    }
    // ptr now points to the node after which a new node is to be inserted
    n->next = ptr->next;
    ptr->next = n;
    return head;
}

void display(node *head) { // To print all the elements in a linked list
    if (isEmpty(head)) {
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

void display_in_reverse(node *ptr) { // To print all the elements in the reverse order
    if (ptr == NULL) {
        return; // Base condition
    }
    display_in_reverse(ptr->next); // Recursive call
    cout << ptr->data << " ";      // This is a case of Head recursion
}

int search(node *head, int key) { // To search a given element/key in a linked list
    node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1; // Could not find the element in the list
}

node *merge(node *head1, node *head2) { // To merge two linked lists into one
    node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    } // temp points to last node of the first list
    temp->next = head2;
    return head1;
}

void sort(node *head) { // To sort the data in the linked list
    node *i = head;
    node *j;

    // Rather than sorting the nodes, this function sorts the data stored in nodes
    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                swap(i->data, j->data);
            }
            j = j->next;
        }
        i = i->next;
    }
} // Brute Force method/ Two pointer approach

node *merge_in_sorted(node *head1, node *head2) { // To merge two sorted list in sorted order

    head1 = merge(head1, head2);
    // Assuming both the lists are already sorted, and merging both the lists into one
    sort(head1);
    return head1;
} // Brute Force Approach

int main() {
    // Head points to the first node of the linked list
    node *head = NULL; // Initially head points to NULL
    // An empty linked list is created...

    head = createNode(0);
    head = insert_at_end(head, 25);
    head = insert_at_end(head, 35);
    head = insert_at_end(head, 45);
    head = insert_at_end(head, 55);
    head = insert_at_end(head, 65);

    display(head);
    display_in_reverse(head);

    cout << "Enter an element to search in the list: ";
    int key;
    cin >> key;
    if (search(head, key)) {
        cout << key << " is Present in the linked list!" << endl;
    } else {
        cout << key << " is Not Present in the linked list!" << endl;
    }

    node *head2 = NULL;
    head2 = createNode(1);
    head2 = insert_at_end(head2, 29);
    head2 = insert_at_end(head2, 39);
    head2 = insert_at_end(head2, 49);
    head2 = insert_at_beg(head2, 59);
    head2 = insert_at_beg(head2, 69);

    display(head2);
    merge(head, head2); // Merging list 2 into list 1
    display(head);

    merge_in_sorted(head, head2);
    display(head);
}