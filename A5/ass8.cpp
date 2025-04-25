// Q8. Combination of all the programs
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

#include "operatorTable.cpp" // File for the declaration of operator Table
#include "stack.cpp"         // File for the declaration of array Stack

// Check the infix expression for balanced parenthesis
bool parenthesisMatch(string str) {
    Stack st;
    st.create(str.length());

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            st.push(str[i]); // Push into stack (in case of opening parenthesis)
        }
        else if (str[i] == ')') {
            if (st.isEmpty())
                return false;
            st.pop(); // Pop from the stack (in case of closing parenthesis)
        }
    }
    if (st.isEmpty())
        return true;
    else
        return false;
}

// Converts an infix expression to postfix
string infixToPostfix(string str) {
    string result = ""; // Declare an empty string

    Stack st;
    st.create(str.length()); // Creates an empty stack

    opTable table;
    table.create(5); // Creates the operator table
    setOperators(table);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if ((ch != '+') && (ch != '-') && (ch != '*') && (ch != '/') && (ch != '^') && (ch != '(') && (ch != ')')) { // In case of an operand
            result += ch;
            // Appends the operand into result
        }
        else { // In case of an operator
            if (st.isEmpty()) {
                st.push(ch);
                continue;
            }

            if (ch == '(') {
                st.push(ch);
            } 
            else if (ch == ')') {
                while (st.topElement() != '(') {
                    result += st.topElement();
                    st.pop();
                }
                st.pop();
            }
            else if ((ch != '^') && (table.getPrecedence(ch) > table.getPrecedence(st.topElement()))) {
                st.push(ch);
            } 
            else if ((ch != '^') && (table.getPrecedence(ch) <= table.getPrecedence(st.topElement()))) {
                while (table.getPrecedence(ch) <= table.getPrecedence(st.topElement())) {
                    result += st.topElement();
                    st.pop();
                }
                st.push(ch);
            } 
            else if ((ch == '^') && (table.getPrecedence(ch) >= table.getPrecedence(st.topElement()))) {
                st.push(ch);
            } 
            else if ((ch == '^') && (table.getPrecedence(ch) < table.getPrecedence(st.topElement()))) {
                while (table.getPrecedence(ch) < table.getPrecedence(st.topElement())) {
                    result += st.topElement();
                    st.pop();
                }
                st.push(ch);
            }
        }
    }

    while (!st.isEmpty()) {
        result += st.topElement();
        st.pop();
    }
    return result;
}

// Read the value of operands from the user input
void readValue(string &post, int n) {
    int *arr = new int[n]; // Declares an empty array for the values
    cout << "Enter the values of all the operands:" << endl;

    int i = 0, j = 0;
    while (post[j] != '\0') {
        char ch = post[j];

        if ((ch != '+') && (ch != '-') && (ch != '*') && (ch != '/') && (ch != '^') && (ch != '(') && (ch != ')')) {
            cout << ch << " = ";
            cin >> arr[i];
            post[j] = arr[i] + '0';
            i++;
        }
        j++;
    }
    // Replaces the source string -> Operands are replaced with value
}

// Evaluate a valid postfix expression (with values)
float evaluate(string post) {
    Stack st;
    st.create(post.length()); // Creates an empty stack

    for (int i = 0; post[i] != '\0'; i++) {
        char ch = post[i];

        if ((ch != '+') && (ch != '-') && (ch != '*') && (ch != '/') && (ch != '^')) {
            // In case of an operand
            st.push(ch - '0');
            // Pushes the value into stack (after converting from char to int)
        }
        else {
            // In case of an operator
            float a = st.pop();
            float b = st.pop();
            switch (ch) {
            case '+':
                st.push((b + a));
                break;
            case '-':
                st.push((b - a));
                break;
            case '*':
                st.push((b * a));
                break;
            case '/':
                st.push((b / a));
                break;
            case '^':
                st.push((pow(b, a)));
                break;
            default:
                cout << "Invalid Expression!" << endl;
                return -1;
            }
        }
    }
    return st.pop();
    // Returns the last element in the stack
}

// Counts the number of operands in the string
int countOperand(string str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if ((ch != '+') && (ch != '-') && (ch != '*') && (ch != '/') && (ch != '^')) {
            count++;
        }
    }
    return count;
}

int main() {
    while (true) {
        string str;
        cout << "Enter a valid infix expression: " << endl;
        cin >> str;

        if (!parenthesisMatch(str)) {
            cout << "Parenthesis are ot balanced!" << endl;
            cout << "Invalid Expression!" << endl;
            continue;
        }

        string post = infixToPostfix(str);

        int n = countOperand(post); // No. of operands in the string
        readValue(post, n); // Inputs the value of the operands from the user
        
        cout << "Evaluated expression: " << endl 
        << evaluate(post) << endl; // Evaluate the postfix expression
    }
    return 0;
}