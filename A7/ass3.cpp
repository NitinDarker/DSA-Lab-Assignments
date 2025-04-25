// Q3. Design a Data Structure in C++ to implement the Queue ADT using an Array using only one variable.
#include <iostream>
using namespace std;

class Queue {
    int *arr; // Linear Array Queue
    int end, currSize, maxSize;

  public:
    Queue(int size) { // Constructor
        maxSize = size;
        arr = new int[maxSize];
        end = -1;
        currSize = 0;
    }

    bool isEmpty();
    bool isFull();
    void enqueue(int newElement);
    int dequeue();
    int top();
};

bool Queue::isEmpty() {
    if (currSize == 0) {
        return true;
    }
    return false;
}

bool Queue::isFull() {
    if (currSize == maxSize) {
        return true;
    }
    return false;
}

void Queue::enqueue(int newElement) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
        return;
    }
    end++;
    arr[end] = newElement;
    cout << "The element enqueued is " << newElement << endl;
    currSize++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty ";
        return -1;
    }
    int dequeued = arr[0];
    int temp = 0; // Temporary pointer
    while (temp != end) {
        arr[temp] = arr[temp + 1]; // Shifting elements in the array
        temp++;
    }
    end--;
    currSize--;
    return dequeued;
}

int Queue::top() {
    if (isEmpty()) {
        cout << "Queue is Empty ";
        return -1;
    }
    return arr[0];
}

int main() {
    Queue q(6);
    q.enqueue(4);
    q.enqueue(14);
    q.enqueue(24);
    q.enqueue(34);
    q.enqueue(44);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}