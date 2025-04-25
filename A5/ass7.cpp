// Q7. Evaluate a postfix expression using stack
#include <iostream>
#include <math.h>
using namespace std;

#include "stack.cpp" // File for the declaration of array Stack

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

int main() {
    string exp;
    cout << "Enter an postfix expression with values to evaluate:" << endl;
    cin >> exp;
    cout << evaluate(exp) << endl;
    return 0;
}