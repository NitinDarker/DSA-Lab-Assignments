// Q2. Stack using linked list
#include <iostream>
using namespace std;

struct node { // Linked List data structure
    int data;
    struct node *next;
};

struct stack { // Stack data structure
  private:
    node *top = NULL; // Creates an empty stack

  public:
    bool isEmpty();
    void push(int data);
    int pop();
    void display();
    int peek(); // Peek from the top of the stack
};

bool stack::isEmpty() {
    if (top == NULL) {
        return true;
    }
    return false;
}

void stack::push(int data) {
    node *n = new node;
    n->data = data;
    n->next = NULL;
    if (isEmpty()) {
        top = n;
        return;
    }
    n->next = top;
    top = n;
}

int stack::pop() {
    if (isEmpty()) {
        cout << "Cannot pop in an Empty Stack!" << endl;
        return -1;
    }
    int x = top->data;
    node *temp = top;
    top = top->next;
    delete temp;
    return x;
}

int stack::peek() {
    if (isEmpty()) {
        cout << "Cannot peek in an Empty Stack" << endl;
        return -1;
    }
    return top->data;
}

void stack::display() {
    if (isEmpty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
    node *temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    stack s;
    s.push(5);
    s.push(6);
    s.push(8);
    s.display();
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.display();
}