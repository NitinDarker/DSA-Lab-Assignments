/*  Write a program in C++ to find all the tokens in a given string separated by space. Also
    write the functions to classify a given token into operator or operands. The given string
    may contain integer or alphabets as operands.
*/
#include <iostream>
#include <string>
using namespace std;

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
        } 
        else {
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
    } 
    else if ((token[0] >= 48) && (token[0] <= 57)) {
        // In case of integers (0 - 9)
        return "operand (integer)";
    } 
    else {
        // Only remaining case is alphabet
        return "operand (alphabet)";
    }
}

// To print the tokens and their type
void printToken(string s) {

    int count = tokenCount(s);        // Counting number of tokens
    string *tokenArray = tokenize(s); // Tokenizing the string

    for (int i = 0; i < count; i++) {
        cout << "Token " << i + 1 << " = " << tokenArray[i] << " -> " << tokenType(tokenArray[i]) << endl;
    }
}

int main() {
    string s;
    cout << endl << endl << endl << endl << endl << endl;
    cout << "Enter a string: " << endl;
    getline(cin, s); // To read the string along with spaces
    cout << endl << endl;
    printToken(s);
    cout << endl << endl << endl << endl << endl << endl;

    return 0;
}