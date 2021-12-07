#include <iostream>

using namespace std;

int main() {
    int sum_of_square = 0;
    
    for (int i = 0; i < 5; i++) {
        int input;
        
        cin >> input;
        
        sum_of_square += input * input;
    }
    
    cout << sum_of_square % 10 << '\n';
    
    return 0;
}
