#include <iostream>

using namespace std;

int main() {
    int input[8];
    
    for (int i = 0; i < 8; i++) {
        cin >> input[i];
    }
    
    bool asc = true;
    bool des = true;
    
    for (int i = 0; i < 8; i++) {
        if (input[i] != i + 1) asc = false;
        if (input[i] != 8 - i) des = false;
    }
    
    if (asc) {
        cout << "ascending" << '\n';
    }
    else if (des) {
        cout << "descending" << '\n';
    }
    else {
        cout << "mixed" << '\n';
    }
    
    return 0;
}
