// Q4. Design a Data Structure in C++ to implement the Queue ADT using the linked list.
#include <iostream>
using namespace std;

class QueueNode { // Node class in a linked list
  public:
    int val;
    QueueNode *next;

    QueueNode(int data) { // Node constructor
        val = data;
        next = nullptr;
    }
};

class Queue {
    QueueNode *Front, *Rare;
    int size;

  public:
    Queue() {
        Front = nullptr;
        Rare = nullptr;
        size = 0;
    }
    bool Empty();
    void Enqueue(int value);
    void Dequeue();
    int Peek();
};

bool Queue::Empty() {
    if (Front == nullptr) {
        return true;
    }
    return false;
}

int Queue::Peek() {
    if (Empty()) {
        cout << "Queue is Empty ";
        return -1;
    } else {
        return Front->val;
    }
}

void Queue::Enqueue(int value) {
    QueueNode *Temp;
    Temp = new QueueNode(value);

    if (Temp == nullptr) { // When heap exhausted
        cout << "Queue is Full" << endl;
        return;
    }

    if (Front == nullptr) {
        Front = Temp;
        Rare = Temp;
    } else {
        Rare->next = Temp;
        Rare = Temp;
    }
    cout << value << " Inserted into Queue " << endl;
    size++;
}

void Queue::Dequeue() {
    if (Front == nullptr) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << Front->val << " Removed From Queue" << endl;
        QueueNode *Temp = Front;
        Front = Front->next;
        delete Temp;
        size--;
    }
}

int main() {
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;
    return 0;
}