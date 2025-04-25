#include <iostream>
using namespace std;

struct node { // Structure for a non-zero element of the linked list
    int row;
    int col;
    int value;
    node *next;
};

struct sparse { // Structure for the sparse matrix
    int srow;
    int scol;
    node *head; // head points the linked list with non-zero elements
};

node *createNode(int row, int col, int value) {
    // Func to create a new node
    node *n = new node;
    n->row = row;
    n->col = col;
    n->value = value;
    n->next = nullptr;
    return n;
}

void create(sparse &s) {
    // Func to create a new sparse matrix
    int m, n, num;
    cout << "Enter rows and columns: ";
    cin >> m >> n;
    s.srow = m;
    s.scol = n;
    s.head = NULL;

    s.head = createNode(-1, -1, -1); // Dummy node
    node *temp = s.head;

    cout << "Enter number of non-zero elements: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
        int r, c, v;
        cout << "Enter row, column, and value: ";
        cin >> r >> c >> v;

        temp->next = createNode(r, c, v);
        temp = temp->next;
    }
    node *temp2 = s.head;
    s.head = s.head->next; // Linked list start from next of dummy node
    delete temp2;          // Deleting the dummy node
}

void display(sparse &s) { // Func to display the sparse matrix
    cout << "Sparse Matrix:\n";
    node *temp = s.head;
    for (int i = 1; i <= s.srow; i++) {
        for (int j = 1; j <= s.scol; j++) {
            if (temp == nullptr) {
                cout << "0 ";
            } else if (temp->row == i && temp->col == j) {
                cout << temp->value << " ";
                temp = temp->next;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void addSparse(sparse &s1, sparse &s2) { // Func to add two sparse matrices
    if (s1.srow != s2.srow || s1.scol != s2.scol) {
        cout << "Cannot add the matrices!";
        return;
    }
    cout << "Addition of both matrices: " << endl;
    node *temp1 = s1.head;
    node *temp2 = s2.head;
    for (int i = 1; i <= s1.srow; i++) {
        for (int j = 1; j <= s1.scol; j++) {
            if (temp1 == nullptr && temp2 == nullptr) {
                cout << "0 ";
            } else if (i == temp1->row && temp1->row == temp2->row && j == temp1->col && temp1->col == temp2->col) {
                cout << temp1->value + temp2->value << " ";
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->row == i && temp1->col == j) {
                cout << temp1->value << " ";
                temp1 = temp1->next;
            } else if (temp2->row == i && temp2->col == j) {
                cout << temp2->value << " ";
                temp2 = temp2->next;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {
    sparse s1;
    cout << "Sparse matrix 1: " << endl;
    create(s1);

    display(s1);

    sparse s2;
    cout << "Sparse matrix 2: " << endl;
    create(s2);

    display(s2);

    cout << "Add: " << endl;
    addSparse(s1, s2);
}