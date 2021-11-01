#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    sort(arr, arr + n);
    
    do {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        
        cout << '\n';
    } while (next_permutation(arr, arr + n));
    
    return 0;
}
