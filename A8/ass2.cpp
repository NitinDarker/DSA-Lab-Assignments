// Q2. Write a program to implement the Hash Table ADT with collision handling mechanism.
#include <iostream>
using namespace std;

class Node { // Linked List
  public:
    int data;
    Node *next;

    Node(int data) { // Constructor to create a new Node
        this->data = data;
        next = NULL;
    }

    Node *insertAtEnd(Node *n) {
        // Inserts node at the end and return head of linked list
        if (this == NULL) {
            // If head Node is NULL
            return n; // n is the new head
        }
        // If head Node is not NULL
        Node *temp = this;
        while (temp->next != NULL) {
            temp = temp->next; // temp points to last node
        }
        temp->next = n;
        return this;
    }
};

class Hash {
  private:
    int size;         // Size of hash Array
    Node **hashArray; // Pointer to dynamic hash Array

  public:
    Hash(int s) { // Constructor
        size = s;
        hashArray = new Node *[size]; // Creating a dynamic array
        for (int i = 0; i < size; i++) {
            // Setting all the elements of array to NULL
            hashArray[i] = NULL;
        }
    }
    // Member functions
    int hashValue(int ele);
    void insert(int ele);
    bool search(int ele);
};

int Hash::hashValue(int ele) {
    // Returns the hashed value for key (index)
    return (ele % size);
}

void Hash::insert(int ele) {
    // Inserts the element into the hash table
    int h = hashValue(ele);

    Node *n = new Node(ele);
    hashArray[h] = hashArray[h]->insertAtEnd(n);
    // Inserts at the end of the linked list present at h-index of hash Array
}

bool Hash::search(int ele) {
    // Searches the element into the hash table
    int h = hashValue(ele);

    Node *temp = hashArray[h];
    while (temp != NULL) { // Traversing the linked list
        if (temp->data == ele) {
            return true; // Element found
        }
        temp = temp->next;
    }
    cout << "No such element is present in the hashArray" << endl;
    return false;
}

int main() {
    Hash table(10);
    table.insert(5); // Inserts 5 in the hash table
    table.insert(15);// Inserts 15 in the hash table
    cout << "The status of 5 in hashArray is: " << table.search(5) << endl;
    cout << "The status of 15 in hashArray is: " << table.search(15) << endl;
    // Both returns true because collision is handled
    return 0;
}