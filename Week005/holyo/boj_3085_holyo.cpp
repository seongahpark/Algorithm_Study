#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

const int adj_r[] = { 0, 1 }, adj_c[] = { 1, 0 };

int main() {
    int n;
    
    cin >> n;
    
    char board[n][n];
    
    for (int ri = 0; ri < n; ri++) {
        for (int ci = 0; ci < n; ci++) {
            cin >> board[ri][ci];
        }
    }
    
    int max_cnt = 1;
    
    for (int cr = 0; cr < n; cr++) {    // cr: current row
        for (int cc = 0; cc < n; cc++) {    // cc: current column
            
            for (int ai = 0; ai < 2; ai++) {    // ai: adj idx
                int ar = cr + adj_r[ai], ac = cc + adj_c[ai];
                
                if (ar >= n || ac >= n) continue;
                
                swap(board[cr][cc], board[ar][ac]);
        
                for (int ri = 0; ri < n; ri++) {
                    int cnt = 1;
                    
                    for (int ci = 1; ci < n; ci++) {
                        if (board[ri][ci] == board[ri][ci - 1]) {
                            max_cnt = max(max_cnt, ++cnt);
                        }
                        else {
                            max_cnt = max(max_cnt, cnt);
                            cnt = 1;
                        }
                    }
                }
                
                for (int ci = 0; ci < n; ci++) {
                    int cnt = 1;
                    
                    for (int ri = 1; ri < n; ri++) {
                        if (board[ri][ci] == board[ri - 1][ci]) {
                            max_cnt = max(max_cnt, ++cnt);
                        }
                        else {
                            max_cnt = max(max_cnt, cnt);
                            cnt = 1;
                        }
                    }
                }
                
                if (max_cnt == n) {
                    cout << n << '\n';
                    
                    return 0;
                }
                
                swap(board[cr][cc], board[ar][ac]);
            }
        }
    }
    
    cout << max_cnt << '\n';
    
    return 0;
}
