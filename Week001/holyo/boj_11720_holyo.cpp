#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    char input[n];
    
    cin >> input;
    
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += input[i] - '0';
    }
    
    cout << sum << '\n';
    
    return 0;
}
