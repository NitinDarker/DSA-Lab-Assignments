// Q1. Write a program in C++ to implement the Hash Table using array.
//     Design the ADT for hash table and implement.
#include <iostream>
using namespace std;

class Hash {
  private:
    int size;       // Size of hashArray
    int *hashArray; // Pointer to dynamic hash Array

  public:
    Hash(int s) { // Constructor
        size = s;
        hashArray = new int[size]; // Creating a new dynamic array
        for (int i = 0; i < s; i++) {
            // Setting the values of all the elements in array to -999
            hashArray[i] = -999;
        }
    }
    // Member functions
    int hashValue(int ele);
    void insert(int ele);
    bool search(int ele);
};

int Hash::hashValue(int ele) {
    // Returns the hashed value for key (index)
    return ele % size;
}

void Hash::insert(int ele) {
    // Inserts element into the hash Array
    int h = hashValue(ele);
    hashArray[h] = ele;
    // Does not account for collision and overwrites the value
}

bool Hash::search(int ele) {
    // Searches the element into the hash table
    int h = hashValue(ele);
    if (hashArray[h] == ele) {
        return true;
    } else
        return false;
}

int main() {
    Hash table(10);   // Creates a hash table of size 10
    table.insert(5);  // Inserts 5 into hash table at index = 5
    table.insert(15); // Overwrites 15 into hash table at index = 5
    cout << "The status of 5 in hashArray is: " << table.search(5) << endl;
    // Returns false because it is overwritten by 15
    return 0;
}