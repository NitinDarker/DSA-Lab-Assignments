// Write a C++ program to represent sparse matrix. Also, performs addition
// of this lower triangular matrix with another simple matrix.
#include <iostream>
using namespace std;

int main() {
    // Taking sparse matrix as a square matrix
    cout << "Enter the order of the matrix: " << endl;
    int order;
    cin >> order;
    int sparse[order][order]; // Declaring a matrix of order given by user

    cout << "Enter the non - zero elements of the matrix - " << endl;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            if (i <= j) {
                sparse[i][j] = 0;
            } else {
                cout << "sparse[" << i << "][" << j << "] = ";
                cin >> sparse[i][j];
            }
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

    cout << "Sparse Matrix: " << endl;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            cout << sparse[i][j] << " ";
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
            cout << matrix[i][j] + sparse[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}