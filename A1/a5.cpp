// Second smallest element of the array
#include <climits>
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 1};
    int n = sizeof(arr) / sizeof(int);
    int smallest = INT_MAX;
    int ss = INT_MAX;
    int index;

    for (int i = 0; i < n; i++) {
        if (smallest > arr[i]) {
            smallest = arr[i];
            index = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (index == i) {
            continue;
        }
        if (ss > arr[i]) {
            ss = arr[i];
        }
    }

    cout << "Smallest element: " << smallest << endl;
    cout << "SSmallest element: " << ss;
}
