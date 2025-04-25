// Stack using Array
#include <iostream>
using namespace std;

struct Stack { // Stack data structure
  private:
    int size, top;
    int *arr;

  public:
    void create(int size);
    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();
    void display();      // Display the elements in a Stack
    int peek(int index); // Peek at any index of the Stack
    int topElement();    // Peek from the top element of Stack
};

void Stack::create(int size) {
    arr = new int[size];
    top = -1;
    this->size = size;
}

bool Stack::isFull() {
    if (top == size - 1) {
        return true;
    }
    return false;
}

bool Stack::isEmpty() {
    if (top == -1) {
        return true;
    }
    return false;
}

void Stack::push(int data) {
    if (isFull()) {
        cout << "Stack is Full" << endl;
        return;
    }
    arr[++top] = data;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    return arr[top--];
}

void Stack::display() {
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Stack::peek(int index) {
    if (index >= size || index < 0) {
        cout << "Invalid index" << endl;
        return -1;
    }
    if (index > top) {
        cout << "Empty" << endl;
        return -1;
    }
    return arr[index];
}

int Stack::topElement() {
    if (isEmpty()) {
        // cout << "Stack is Empty!" << endl;
        return -1;
    }
    return arr[top];
}