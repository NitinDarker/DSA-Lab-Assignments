// Write a C++ program to compute the power of any given number using recursion.
#include <iostream>
using namespace std;

int pow(int num, int exp) { // Recursive power function
    if (exp == 0) {
        return 1; // Base condition
    }
    return num * pow(num, exp - 1); // Recursive call of pow
}

int main() {
    int num, exp;
    cout << "Enter a number: ";
    cin >> num; // Inputting the number from user
    cout << "Enter its power: ";
    cin >> exp; // Inputting the exponent from the user

    if (exp < 0) {
        cout << "Enter a valid exponent" << endl;
        exit(0);
    }

    cout << num << "^" << exp << " = " << pow(num, exp) << endl;
    return 0;
}