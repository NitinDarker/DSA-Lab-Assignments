#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Input the number of elements in an array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Input each element of the array - " << endl;

    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    cout << "Elements of the array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

