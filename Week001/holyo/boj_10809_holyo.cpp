#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    
    cin >> input;
    
    int cnt[26];

    for (int i = 0; i < 26; i++) {
        cnt[i] = -1;
    }
    
    for (int i = 0; i < input.length(); i++) {
        int idx = input[i] - 'a';
        
        if (cnt[idx] == -1) {
            cnt[idx] = i;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        cout << cnt[i] << ' ';
    }
    
    return 0;
}
