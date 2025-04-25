// Q4. Balanced parenthesis using Stack ('()', '{}', '[]')
#include <iostream>
using namespace std;

#include "stack.cpp" // Includes the array stack structure

bool parenthesisMatch(string str) {
    Stack st;
    st.create(str.size());

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch); // Push into stack (in case of opening parenthesis)
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty())
                return false;
            switch (ch) {
            case ')':
                if (st.topElement() != '(') // Checks the top of the stack
                    return false;
                st.pop(); // Pop from the stack (in case of '(')
                break;

            case '}':
                if (st.topElement() != '{') // Checks the top of the stack
                    return false;
                st.pop(); // Pop from the stack (in case of '{')
                break;

            case ']':
                if (st.topElement() != '[') // Checks the top of the stack
                    return false;
                st.pop(); // Pop from the stack (in case of '[')
                break;
            }
        }
    }
    if (st.isEmpty()) {
        return true;
    }
    return false;
}

int main() {
    cout << "Input a string: ";
    string str;
    cin >> str;
    cout << parenthesisMatch(str) << endl;
    return 0;
}