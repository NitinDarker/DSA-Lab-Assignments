// Write a C++ program to find the nth term of a Fibonacci series using recursion.
#include <iostream>
using namespace std;

int fib(int n) { // Recursive fib function
    if (n == 0) {
        return 0; // Base condition - 1
    }
    if (n == 1) {
        return 1; // Base condition - 2
    }
    return fib(n - 1) + fib(n - 2); // Recursive call of fib
}

int main() {
    int n; // For n = number of digits in fibonacci sequence
    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 0) {
        cout << "Enter a valid value of n!" << endl;
        exit(0);
    }

    cout << "fib(n) = " << fib(n) << endl;
    return 0;
}