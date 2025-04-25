#include <iostream>
#include <climits>
using namespace std;

struct array {
    int size;  // Storing Capacity of array
    int *data; // data points to the first element of the array
    int ptr;   // ptr stores the index of the last element in array
};

void create(array &arr, int size) { // Function to initialize an Array ADT
    arr.size = size;
    arr.data = new int[size];
    arr.ptr = -1; // Array is empty
}

void append(array &arr, int val) { // Appends an element at the end of the array
    if (arr.ptr == arr.size - 1) {
        cout << "Cannot Append in a full array!" << endl;
        return;
    }
    arr.data[arr.ptr + 1] = val;
    arr.ptr++;
    
}

void display(array &arr) { // To display the elements in an array
    for (int i = 0; i <= arr.ptr; i++) {
        cout << arr.data[i] << " ";
    }
}

void insertIndex(array &arr, int val, int index) { // To insert an element at any given index
    if (arr.ptr == arr.size - 1) {
        cout << "Cannot insert in a full array!" << endl;
        return;
    }
    if (index >= arr.size) {
        cout << "Invalid Index!" << endl;
        return;
    }
    int p = arr.ptr; // Creating a temporary pointer p
    while (p >= index) {
        arr.data[p + 1] = arr.data[p]; // Shifting elements to the right
        p--;
    }
    arr.data[p + 1] = val;
    arr.ptr++;
}

void removeElement(array &arr, int element) { // To remove given element from the array
    int i, j;
    for (i = 0; i <= arr.ptr; i++) {
        if (arr.data[i] == element) {
            break;
        } // i has index where element is stored in array
    }
    if (i > arr.ptr) {
        cout << "Element not found!" << endl;
        return;
    }
    for (j = i; j < arr.ptr; j++) {
        arr.data[j] = arr.data[j + 1];
    } // Shifting elements to the left
    arr.ptr--;
}

int get(array &arr, int index) { // To retrieve the value at any given index
    if (index < 0 || index > arr.ptr) {
        cout << "Invalid Index!" << endl;
        return -1;
    }
    return arr.data[index];
}

void sort(array &arr) { // Brute Force algorithm
    for (int i = 0; i <= arr.ptr; i++) {
        for (int j = i + 1; j <= arr.ptr; j++) {
            if (arr.data[i] > arr.data[j]) {
                swap(arr.data[i], arr.data[j]);
            }
        }
    }
}

int max(array &arr) { // To find greatest number from the array
    int max = INT_MIN;
    for (int i = 0; i <= arr.ptr; i++) {
        if (arr.data[i] > max) {
            max = arr.data[i];
        }
    }
    return max;
}

int main() {
    array arr;
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    create(arr, size);

    cout << "Enter a value to append: ";
    int value;
    cin >> value;
    append(arr, value);

    append(arr, 4);
    append(arr, 3);
    append(arr, 0);
    append(arr, 2);
    append(arr, 1);
    append(arr, 8);

    cout << "Enter a value to insert: ";
    int value2;
    cin >> value2;
    cout << "Enter the index at which value is to be inserted: ";
    int ind;
    cin >> ind;
    insertIndex(arr, value2, ind);
    display(arr);

    cout << "Enter a value to remove: ";
    int rem;
    cin >> rem;
    removeElement(arr, rem);
    display(arr);

    cout << get(arr, 2) << endl;

    sort(arr);

    cout << max(arr) << endl;

    display(arr);
}