#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int dir_r[] = {-1, 0, 1, 0};    // up, right, down, left
int dir_c[] = {0, 1, 0, -1};

int main() {
    int r, c, k;
    
    cin >> r >> c >> k;
    
    bool is_trash[r][c];
    bool is_visited[r][c];
    
    memset(is_trash, false, sizeof(is_trash));
    memset(is_visited, false, sizeof(is_visited));
    
    while (k--) {
        int tr, tc;
        
        cin >> tr >> tc;
        
        is_trash[tr - 1][tc - 1] = true;
    }
    
    int max_trash = 0;
    
    for (int sr = 0; sr < r; sr++) {
        for (int sc = 0; sc < c; sc++) {
            if (is_visited[sr][sc]) continue;
            if (!is_trash[sr][sc]) continue;
            
            int cnt = 0;
            queue<pair<int, int>> q;
            
            q.push(make_pair(sr, sc));
            is_visited[sr][sc] = true;;
            
            while (!q.empty()) {
                int cr = q.front().first, cc = q.front().second;
                
                q.pop();
                cnt++;
                
                for (int di = 0; di < 4; di++) {
                    int nr = cr + dir_r[di], nc = cc + dir_c[di];
                    
                    if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
                    if (is_visited[nr][nc]) continue;
                    if (!is_trash[nr][nc]) continue;
                    
                    q.push(make_pair(nr, nc));
                    is_visited[nr][nc] = true;
                }
            }
            
            if (cnt > max_trash) max_trash = cnt;
        }
    }
    
    cout << max_trash << '\n';
    
    return 0;
}
