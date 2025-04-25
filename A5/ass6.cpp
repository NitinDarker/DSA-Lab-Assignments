// Q6. Convert infix to Postfix using Stack
#include <iostream>
using namespace std;

#include "stack.cpp"     // File for the declaration of character Stack
#include "operatorTable.cpp" // File for the declaration of operator Table

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

int main() {
    string exp;
    cout << "Enter an infix expression: " << endl;
    cin >> exp;
    cout << "Infix to Postfix: \n"
         << infixToPostfix(exp) << endl;
    return 0;
}