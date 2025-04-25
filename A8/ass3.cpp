// Q3. Assume, an application needs to store the name and branch information of some
// random students. This application required functionality that we can search the
// student’s information by providing the roll number of the student.
// Therefore, design a hash table ADT for the same, where the roll number may be
// selected as key of the information. Implement the same in C++.

#include <iostream>
using namespace std;

struct studentInfo { // ADT for student information
    int rollNo;      // To store the roll number of the student
    string name;     // To store the name of the student
    string branch;   // To store the branch info of the student
};

class Node { // Linked List
  public:
    studentInfo data; // data is of studentInfo ADT type
    Node *next;

    Node(studentInfo data) { // Constructor to create a new Node
        this->data = data;
        next = NULL;
    }

    Node *insertAtEnd(Node *n) {
        // Inserts node at the end and return head of linked list
        if (this == NULL) {
            // If head Node is NULL
            cout << "inserted " << n->data.name << " into the database" << endl;
            return n; // n is the new head
        }
        // If head Node is not NULL
        Node *temp = this;
        while (temp->next != NULL) {
            temp = temp->next; // temp points to last node
        }
        temp->next = n;
        cout << "inserted " << n->data.name << " into the database" << endl;
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
    int hashValue(int rollNo);
    void insert(studentInfo data);
    void search(int rollNo);
};

int Hash::hashValue(int rollNo) {
    // Returns the hashed value for key (index)
    return (rollNo % size) - 1;
}

void Hash::insert(studentInfo data) {
    // Inserts the element into the hash table
    int h = hashValue(data.rollNo);

    Node *n = new Node(data);
    hashArray[h] = hashArray[h]->insertAtEnd(n);
    // Inserts at the end of the linked list present at h-index of hash Array
}

void Hash::search(int rollNo) {
    // Searches the student into the hash table based on its rollNo and prints its info
    if ((rollNo > size) || (rollNo <= 0)) {
        cout << "Roll number does not exist!" << endl;
        return;
    }

    int h = hashValue(rollNo);
    cout << "Student Details: " << endl;

    Node *temp = hashArray[h];
    while (temp != NULL) { // Traversing the linked list
        if (temp->data.rollNo == rollNo) {
            cout << "Student Name: " << temp->data.name << endl;
            cout << "Student Branch: " << temp->data.branch << endl;
        }
        temp = temp->next;
    }
}

int main() {
    Hash table(25); // Creates a hash table to store info of students

    studentInfo student1; // Student 1
    student1.rollNo = 16;
    student1.name = "Nitin Sharma";
    student1.branch = "CSE";

    studentInfo student2; // Student 2
    student2.rollNo = 14;
    student2.name = "Mohit Sharma";
    student2.branch = "CSE";
 
    studentInfo student3; // Student 3
    student3.rollNo = 16;
    student3.name = "Yash Shukla";
    student3.branch = "ECE"; // Case of collision 

    table.insert(student1);
    table.insert(student2);
    table.insert(student3);

    table.search(16); // Prints the info of both the students with rollNo = 16

    return 0;
}