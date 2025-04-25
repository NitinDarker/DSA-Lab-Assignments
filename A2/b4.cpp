// Write a C++ program to represent the polynomial equation using structure. Also, write
// the function to evaluate the polynomial equation for a given value of x.
#include <iostream>
#include <cmath>
using namespace std;

struct Polynomial { // Structure to define a Polynomial
    int degree;
    float *coefficients; // Dynamically allocated array for coefficients
};

float evaluatePolynomial(Polynomial poly, float x) {
    // Function to find out the value of Polynomial with a given value of x
    float result = 0.0;
    for (int i = poly.degree; i >= 0; i--) {
        result += poly.coefficients[i] * pow(x, i);
    }
    return result;
}

int main() {
    Polynomial poly;

    cout << "Enter the degree of the polynomial: ";
    cin >> poly.degree;

    poly.coefficients = new float[poly.degree + 1]; // Allocate memory for coefficients

    cout << "Enter the coefficients:\n";
    for (int i = poly.degree; i >= 0; i--) {
        cin >> poly.coefficients[i];
    }

    float x;
    cout << "Enter the value of x: ";
    cin >> x;

    float result = evaluatePolynomial(poly, x);
    cout << "The value of the polynomial at x = " << x << " is: " << result << endl;

    delete[] poly.coefficients; // Deallocate memory for coefficients

    return 0;
}