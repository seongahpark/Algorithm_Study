#include <iostream>

using namespace std;

int main() {
    int n, m;
    
    cin >> n >> m;
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int cnt = 0;
    int sum = 0;
    int s = 0, e = 0;
    
    while (s < n) {
        if (sum >= m) {
            if (sum == m) cnt++;
            
            sum -= arr[s++];
        }
        else  sum += arr[e++];
    }
    
    cout << cnt << '\n';
    
    return 0;
}
