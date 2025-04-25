// Write a C++ program to compute following equation up to the n term using recursion:
#include <cmath>
#include <iostream>
using namespace std;

int fact(int n) { // Recursive factorial function
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

float pow(int num, int exp) { // Recursive Power function
    if (exp == 0) {
        return 1;
    }
    return num * pow(num, exp - 1);
}

float term(int x, int n) {
    return (pow(x, n - 1)) / (fact(n - 1));
}

float equation(int n, int x) { // Recursive func to calculate the equation
    if (n == 1) {
        return 1; // Base condition
    }
    return term(x, n) + equation(n - 1, x);
    // Recursive call of equation
}

int main() {
    int n, x;
    cout << "Enter the number of terms(n): ";
    cin >> n;
    cout << "Enter the value of x: ";
    cin >> x;

    if (n < 1) {
        cout << "Enter a valid value of n!" << endl;
        exit(0);
    }

    cout << "e^x = " << equation(n, x) << endl;
    return 0;
}