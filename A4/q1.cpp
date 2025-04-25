// Design a data structure to represent a polynomial using linked list
#include <iostream>
using namespace std;

struct node { // Structure to represent a node linked list
    int data;
    node *next;
};

struct poly { // Structure to store a polynomial
    int degree;
    node *head;
    // head points to the linked list of all the coefficients of poly
};

node *createNode(int data) { // Function to create a new node
    node *n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

void addNode(poly *p, int data) {
    // Function to insert a new node at the end of the linked list
    if (p->head == NULL) {
        p->head = createNode(data);
        return;
    }
    node *temp = p->head;
    while (temp->next != NULL) {
        temp = temp->next; // Temp points to the last node
    }
    temp->next = createNode(data);
}

void inputPoly(poly *p) {
    // Function to input the coefficients of the polynomial
    // No. of coefficients = degree + 1
    for (int i = p->degree; i >= 0; i--) {
        cout << "coeff of x^" << i << " = ";
        int coeff;
        cin >> coeff;
        addNode(p, coeff);
    // Calls the addNode func to insert the coeff at the end of the linked list
    }
}

void display_poly(poly *p) {
    // Function to display the polynomial equation
    node *temp = p->head;
    for (int i = p->degree; i >= 0; i--) {
        if (i == 0) { // For the last (constant) term of the equation
            cout << temp->data << endl;
            return;
        }
        if (temp->data == 0) {
            // If any coeff is 0, then do not print the term
            temp = temp->next;
            continue;
        }
        cout << temp->data << "x^" << i << " + ";
        temp = temp->next;
    }
    cout << endl;
}

poly *add_poly(poly *p1, poly *p2) { // Function to add two polynomial equations
    poly *sum = new poly;
    sum->head = NULL;
    sum->degree = max(p1->degree, p2->degree);
    node *temp1 = p1->head; // Temporary pointer to traverse poly-1
    node *temp2 = p2->head; // Temporary pointer to traverse poly-2
    if (p1->degree > p2->degree) {
        node *temp = p1->head;
        int diff = p1->degree - p2->degree;
        while (diff--) {
            addNode(sum, temp->data);
            temp = temp->next;
        }
        temp1 = temp;
    } else if (p1->degree < p2->degree) {
        node *temp = p2->head;
        int diff = p2->degree - p1->degree;
        while (diff--) {
            addNode(sum, temp->data);
            temp = temp->next;
        }
        temp2 = temp;
    }
    while (temp1 != NULL) {
        addNode(sum, temp1->data + temp2->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return sum;
}

int main() {
    poly *p1 = new poly;
    poly *p2 = new poly;

    p1->head = NULL;
    p2->head = NULL;

    cout << "Enter the degree of the polynomial 1: ";
    cin >> p1->degree;

    cout << "Enter the degree of the polynomial 2: ";
    cin >> p2->degree;

    cout << "Enter the value of coefficients of p1: " << endl;
    inputPoly(p1);
    cout << "p1: ";
    display_poly(p1);

    cout << "Enter the value of coefficients of p1: " << endl;
    inputPoly(p2);
    cout << "p2: ";
    display_poly(p2);

    poly *p3 = add_poly(p1, p2);
    
    cout << "p3: ";
    display_poly(p3);
}