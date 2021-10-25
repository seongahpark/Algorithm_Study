#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    bool prime_arr[n + 1];
    
    memset(prime_arr, true, sizeof(prime_arr));
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (!prime_arr[i]) continue;
        
        for (int mult = i * i; mult <= n; mult += i) {
            prime_arr[mult] = false;
        }
    }
    
    vector<int> prime;
    
    for (int i = 2; i <= n; i++) {
        if (prime_arr[i]) prime.push_back(i);
    }
    
    int s = 0, e = 0, sum = 0, cnt = 0;
    int cnt_prime = prime.size();
    
    while (s < cnt_prime) {
        if (sum >= n || e == cnt_prime) {
            if (sum == n) cnt++;
            
            sum -= prime[s++];
        }
        else sum += prime[e++];
    }
    
    cout << cnt << '\n';
    
    return 0;
}
