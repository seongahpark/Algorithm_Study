#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int arr[n];
    
    for (int idx = 0; idx < n; idx++) {
        cin >> arr[idx];
    }
    
    sort(arr, arr + n);
    
    int x;
    
    cin >> x;
    
    int l = 0, r = n - 1, cnt = 0;
    
    while (l < r) {
        long long sum = arr[l] + arr[r];
        
        if (sum >= x) {
            if (sum == x) cnt++;
            
            r--;
        }
        else l++;
    }
    
    cout << cnt << '\n';
    
    return 0;
}
