// Write a C++ program to store lower triangular matrix. Also, performs addition
// of this lower triangular matrix with another simple matrix.
#include <iostream>
using namespace std;

int main() {
    // Lower Triangular matrix are square matrix by definition
    cout << "Enter the order of the matrix: " << endl;
    int order;
    cin >> order;
    int tri[order][order]; // Declaring a matrix of order given by user

    cout << "Enter the lower triangular elements of the matrix - " << endl;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            if (i < j) {
                tri[i][j] = 0;
            } else {
                cout << "tri[" << i << "][" << j << "] = ";
                cin >> tri[i][j];
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

    cout << "Lower Triangular Matrix: " << endl;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            cout << tri[i][j] << " ";
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
            cout << matrix[i][j] + tri[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}