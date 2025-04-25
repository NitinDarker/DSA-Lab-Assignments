// Q1. Write a program in C++ to find all the tokens in a given string separated by space.
//     Convert string to integers if any.

#include <iostream>
#include <string>
using namespace std;

// Assuming only positive integers
int stringToInteger(string s) {
    int result = 0;
    for (char ch : s) {       // Using for-each loop
        int digit = ch - '0'; // Converting every char digit into integer
        result = result * 10 + digit;
    }
    return result;
}

// To count the number of tokens in the given string
int tokenCount(string s) {
    int count = 0;
    for (char ch : s) { // Using For-each loop
        if (ch == ' ') {
            count++; // Counts the number of spaces in the string
        }
    }
    return count + 1; // Tokens = no. of spaces + 1
}

// To tokenize the string and store the tokens in a string-array
string *tokenize(string s) {
    int count = tokenCount(s);
    string *tokenArray = new string[count]; // Initialising the string-array

    int i = 0;          // TokenArray counter
    for (char ch : s) { // Using For-each loop
        if (ch != ' ') {
            tokenArray[i] += ch; // Appending the char in the tokenArray[i]
        } else {
            i++;
        }
    }
    return tokenArray;
}

// To return the type of token as a string
// Assuming the token contains either operator or alphabet or integer
string tokenType(string token) {
    if ((token == "+") || (token == "-") || (token == "*") || (token == "/") || (token == "^")) {
        // Assuming only these 5 operators
        // If number of operators increases then we will implement operator table data structure
        return "operator";
    } else if ((token[0] >= 48) && (token[0] <= 57)) {
        // In case of integers (0 - 9)
        return "operand (integer)";
    } else {
        // Only remaining case is alphabet
        return "operand (alphabet)";
    }
}

// To print the tokens and their type
void printToken(string s) {

    int count = tokenCount(s);          // Counting number of tokens
    string *tokenArray = tokenize(s);   // Tokenizing the string
    int *integerToken = new int[count]; // Integer token array
    int j = 0;                          // Integer token array counter

    for (int i = 0; i < count; i++) {
        cout << "Token " << i + 1 << " = " << tokenArray[i] << " -> " << tokenType(tokenArray[i]) << endl;
        if (tokenType(tokenArray[i]) == "operand (integer)") {
            integerToken[j] = stringToInteger(tokenArray[i]);
            // If token is integer then convert into int
            j++;
        }
    }
}

int main() {
    string s;
    cout << "Enter a string: " << endl;
    getline(cin, s); // To read the string along with spaces
    printToken(s);
    return 0;
}