#include <iostream>

using namespace std;

const int CNT_TET = 19;
const int R = 0, C = 1;

const int TET[CNT_TET][2][3] = {
    {{0, 1, 1}, {1, 0, 1}},
    {{0, 0, 0}, {1, 2, 3}},
    {{1, 2, 3}, {0, 0, 0}},
    {{1, 2, 2}, {0, 0, 1}},
    {{1, 2, 2}, {0, 0, -1}},
    {{0, 1, 2}, {1, 0, 0}},
    {{0, 1, 2}, {1, 1, 1}},
    {{1, 1, 1}, {0, 1, 2}},
    {{0, 0, 1}, {1, 2, 0}},
    {{0, 0, 1}, {1, 2, 2}},
    {{1, 1, 1}, {-2, -1, 0}},
    {{1, 1, 2}, {0, 1, 1}},
    {{1, 1, 2}, {-1, 0, -1}},
    {{0, 1, 1}, {1, 1, 2}},
    {{0, 1, 1}, {1, -1, 0}},
    {{1, 1, 1}, {-1, 0, 1}},
    {{0, 0, 1}, {1, 2, 1}},
    {{1, 1, 2}, {0, 1, 0}},
    {{1, 1, 2}, {-1, 0, 0}},
};

int main() {
    int r, c;
    
    cin >> r >> c;
    
    int board[r][c];
    
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            cin >> board[ri][ci];
        }
    }
    
    int max_sum = 0;
    
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            
            for (int ti = 0; ti < CNT_TET; ti++) {
                bool can_put = true;
                int sum = board[ri][ci];
                
                for (int i = 0; i < 3; i++) {
                    int nr = ri + TET[ti][R][i], nc = ci + TET[ti][C][i];
                    
                    if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
                        can_put = false;
                        
                        break;
                    }
                    
                    sum += board[nr][nc];
                }
                
                if (!can_put) continue;
                
                max_sum = max(max_sum, sum);
            }
        }
    }
    
    cout << max_sum << '\n';
    
    return 0;
}
