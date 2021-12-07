#include <iostream>
#include <string>

using namespace std;

int main() {
    int tc;
    
    cin >> tc;
    
    while (tc--) {
        int rep;
        string input;
        
        cin >> rep >> input;
        
        int len = input.length();
        
        for (int i = 0; i < len; i++) {
            for (int ri = 0; ri < rep; ri++) {
                cout << input[i];
            }
        }
        
        cout << '\n';
    }
    
    return 0;
}
