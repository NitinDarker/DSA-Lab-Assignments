// Write a C++ program to store a diagonal matrix. matrix. Also, performs addition of this
// diagonal matrix with another simple matrix.
#include <iostream>
using namespace std;

int main() {
    // Diagonal matrix are square matrix by definition
    int order;
    cout << "Enter the order of the matrix: ";
    cin >> order;

    int diag[order][order];
    // Diagonal matrix = All the elements except the diagonal are zero

    cout << "Input the diagonal elements of the diag - " << endl;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            if (i == j)
                cin >> diag[i][j]; // Only inputting the diagonal elements
            else
                diag[i][j] = 0; // Setting every non-diagonal element to be zero
        }
    }

    int matrix[order][order];
    // Declaring a regular matrix

    cout << "Input the elements of the regular matrix - " << endl;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Diagonal Matrix: " << endl;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            cout << diag[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Regular Matrix: " << endl;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Sum of both these matrices - " << endl;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            cout << matrix[i][j] + diag[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}