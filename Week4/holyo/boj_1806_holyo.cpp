#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n, threshold;
    
    cin >> n >> threshold;
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int min_len = INT_MAX;
    int s = 0, e = 0, sum = 0;
    
    while (s < n) {
        if (sum >= threshold) {
            int len = e - s;
            
            if (len < min_len) min_len = len;
            
            sum -= arr[s++];
        }
        else if (e == n) {
            sum -= arr[s++];
        }
        else sum += arr[e++];
    }
    
    if (min_len == INT_MAX) min_len = 0;
    
    cout << min_len << '\n';
    
    return 0;
}
