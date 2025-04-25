#include <iostream>
using namespace std;

int main() {

    int sales = 46;
    int percent = 62;

    cout << "This year's sales = " << sales << " lakhs" << endl;

    float profit = (sales * percent) / 100.0;

    cout << "This year's profit = " << profit << " lakhs" << endl;

    return 0;
}

