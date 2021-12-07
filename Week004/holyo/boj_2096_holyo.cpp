#include <iostream>

using namespace std;

const int N = 3;

int min_sum[N];
int max_sum[N];

int main() {
    int n;
    
    cin >> n;
    
    while (n--) {
        int input[N];
        
        for (int i = 0; i < N; i++) {
            cin >> input[i];
        }
        
        int min_tmp[N], max_tmp[N];
        
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                min_tmp[i] = min(min_sum[i], min_sum[i + 1]) + input[i];
                max_tmp[i] = max(max_sum[i], max_sum[i + 1]) + input[i];
            }
            else if (i == N - 1) {
                min_tmp[i] = min(min_sum[i], min_sum[i - 1]) + input[i];
                max_tmp[i] = max(max_sum[i], max_sum[i - 1]) + input[i];
            }
            else {
                min_tmp[i] = min(min_sum[i], min(min_sum[i - 1], min_sum[i + 1])) + input[i];
                max_tmp[i] = max(max_sum[i], max(max_sum[i - 1], max_sum[i + 1])) + input[i];
            }
        }
        
        for (int i = 0; i < N; i++) {
            min_sum[i] = min_tmp[i];
            max_sum[i] = max_tmp[i];
        }
    }
    
    int min_score = min_sum[0], max_score = max_sum[0];
    
    for (int i = 1; i < N; i++) {
        min_score = min(min_score, min_sum[i]);
        max_score = max(max_score, max_sum[i]);
    }
    
    cout << max_score << ' ' << min_score << '\n';
    
    return 0;
}
