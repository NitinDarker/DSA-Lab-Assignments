// Write a C++ program to compute the sum of n natural numbers using recursion.
#include <iostream>
using namespace std;

int sumNatural(int n) { // Recursive function
    if (n == 1) {
        return 1; // Base Condition
    }
    return n + sumNatural(n - 1); // Recursive call of sumNatural
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 1) {
        cout << "Enter a natural number!" << endl;
        exit(0);
    }

    cout << "Sum of " << n << " natural numbers is: " << sumNatural(n) << endl;
    return 0;
}