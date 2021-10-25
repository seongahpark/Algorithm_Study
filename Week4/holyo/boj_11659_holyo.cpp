#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, m;
    
    cin >> n >> m;
    
    int prefix_sum[n + 1];
    
    memset(prefix_sum, 0, sizeof(prefix_sum));
    
    for (int idx = 1; idx <= n; idx++) {
        int input;
        
        scanf("%d", &input);
        
        prefix_sum[idx] = prefix_sum[idx - 1] + input;
    }
    
    while (m--) {
        int l, r;
        
        scanf("%d %d", &l, &r);
        
        int sum = prefix_sum[r] - prefix_sum[l - 1];
        
        printf("%d\n", sum);
    }
    
    return 0;
}
