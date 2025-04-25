#include <iostream>
#include <limits.h>
using namespace std;

int main() {

    int size;
    cout << "Input the number of elements in an array: ";
    cin >> size;

    int arr[size];

    cout << "Input each element of the array - " << endl;

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++) {

        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
    }

    cout << "Second smallest element is: " << secondSmallest << endl;

    return 0;
}


