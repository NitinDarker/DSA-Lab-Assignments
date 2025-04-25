// Q5. Design a data structure to store the operators in a Table
#include <iostream>
using namespace std;

struct op {
    char symbol;
    int pre; // Precedence -> 1,2,3
    int aso; // Associativity -> 0 (L-R), 1 (R-L)
};

struct opTable {
  private:
    int size; // No. of operators to be stored
    op *arr;  // Array to store all the operators
    int top;  // Top points to last operator element

  public:
    void create(int size); // Create a new operator table
    void setOperator(char sym, int pre, bool aso);
    void display();                    // Display the operator table
    bool checkOperator(char symbol);   // To check if an op is in the table or not
    int getPrecedence(char symbol);    // To return the precedence of an operator
    int getAssociativity(char symbol); // To return the associativity of an operator
};

void opTable::create(int size) {
    this->size = size;
    arr = new op[size];
    top = -1;
}

void opTable::setOperator(char sym, int pre, bool aso) {
    if (top == size - 1) {
        cout << "Operator Table full" << endl;
        return;
    }
    top++;
    arr[top].symbol = sym;
    arr[top].pre = pre;
    arr[top].aso = aso;
}

void opTable::display() {
    for (int i = 0; i <= top; i++) {
        cout << arr[i].symbol << " ";
        cout << arr[i].pre << " ";
        cout << arr[i].aso << endl;
    }
}

bool opTable::checkOperator(char symbol) {
    for (int i = 0; i <= top; i++) {
        if (arr[i].symbol == symbol)
            return true;
    }
    return false;
}

int opTable::getPrecedence(char symbol) {
    for (int i = 0; i <= top; i++) {
        if (arr[i].symbol == symbol)
            return arr[i].pre;
    }
    return -1;
}

int opTable::getAssociativity(char symbol) {
    for (int i = 0; i <= top; i++) {
        if (arr[i].symbol == symbol)
            return arr[i].aso;
    }
    return -1;
}

// Function to store the operators in the table
void setOperators(opTable &table) {
    table.setOperator('+', 1, 0);
    table.setOperator('-', 1, 0);
    table.setOperator('*', 2, 0);
    table.setOperator('/', 2, 0);
    table.setOperator('^', 3, 1);
}

int main() {
    opTable table;
    table.create(5);
    setOperators(table);
    table.display();
    return 0;
}