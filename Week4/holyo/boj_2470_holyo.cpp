#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int l = 0, r = n - 1;
    int min_diff = INT_MAX, min_l = 0, min_r = n - 1;
    
    while (l < r) {
        int sum = arr[l] + arr[r];
        
        if (abs(sum) < min_diff) {
            min_l = l;
            min_r = r;
            min_diff = abs(sum);
        }
        
        if (sum <= 0) {
            if (sum == 0) {
                min_l = l;
                min_r = r;
                
                break;
            }
            
            l++;
        }
        else r--;
        
        
    }
    
    cout << arr[min_l] << ' ' << arr[min_r] << '\n';
    
    return 0;
}
