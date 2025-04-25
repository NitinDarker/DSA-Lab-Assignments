// Q3. Balanced parenthesis using Stack (only '()')
#include <iostream>
using namespace std;

#include "stack.cpp" // Includes the array stack structure

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

int main() {
    cout << "Input a string: ";
    string str;
    cin >> str;
    cout << parenthesisMatch(str) << endl;
    return 0;
}