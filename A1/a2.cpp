#include <iostream>
using namespace std;

int main() {

    float price;
    cout << "Input the purchase price (in rupees): ";
    cin >> price;

    float sTax = 0.04;
    float cTax = 0.02;

    cout << "Purchase Price: " << price << " rupees" << endl;
    cout << "State Tax: " << price * sTax << " rupees" << endl;
    cout << "Country Tax: " << price * cTax << " rupees" << endl;
    cout << "Total Amount after Tax: " << price + price * 0.06 << " rupees" << endl;

    return 0;
}

