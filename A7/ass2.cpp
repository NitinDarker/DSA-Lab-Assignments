// Q2. Design a Data Structure in C++ to implement the Queue ADT using an Array.
#include <iostream>
using namespace std;

class Queue {
    int *arr; // Linear Array Queue
    int start, end, maxSize;

  public:
    Queue(int size) { // Constructor
        maxSize = size;
        arr = new int[maxSize];
        start = -1;
        end = -1;
    }

    bool isEmpty();
    bool isFull();
    void enqueue(int newElement);
    int dequeue();
    int top();
};

bool Queue::isEmpty() {
    if (start == -1) {
        return true;
    }
    return false;
}

bool Queue::isFull() {
    if (end == maxSize - 1) {
        return true;
    }
    return false;
}

void Queue::enqueue(int newElement) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
        return;
    }

    if (isEmpty()) {
        start = 0;
        end = 0;
    } else {
        end++;
        // end = (end + 1) % maxSize;
    }
    arr[end] = newElement;
    cout << "The element enqueued is " << newElement << endl;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty ";
        return -1;
    }
    int dequeued = arr[start];
    start++;
    // start = (start + 1) % maxSize;
    return dequeued;
}

int Queue::top() {
    if (isEmpty()) {
        cout << "Queue is Empty ";
        return -1;
    }
    return arr[start];
}

int main() {
    Queue q(5);
    q.enqueue(4);
    q.enqueue(14);
    q.enqueue(24);
    q.enqueue(34);
    cout << "The first element to be deleted " << q.dequeue() << endl;
    cout << "The second element to be deleted " << q.dequeue() << endl;
    return 0;
}