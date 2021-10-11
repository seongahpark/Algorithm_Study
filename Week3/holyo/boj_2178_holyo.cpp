#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int CNT_DIR = 4;

int dir_r[] = {-1, 0, 1, 0};    // up, right, down, left
int dir_c[] = {0, 1, 0, -1};

struct move_info {
    int r;
    int c;
    int cnt = 1;
};

int main(int argc, const char * argv[]) {
    int r, c;
    
    cin >> r >> c;
    
    char maze[r][c];
    bool is_visited[r][c];
    
    memset(is_visited, false, sizeof(is_visited));
    
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            cin >> maze[ri][ci];
        }
    }
    
    queue<move_info> q;
    
    q.push({0, 0});
    is_visited[0][0] = true;
    
    while (!q.empty()) {
        int cr = q.front().r, cc = q.front().c, cnt = q.front().cnt;
        
        if (cr == r - 1 && cc == c - 1) {
            cout << cnt << '\n';
            
            return 0;
        }
        
        q.pop();
        
        for (int di = 0; di < CNT_DIR; di++) {
            int nr = cr + dir_r[di], nc = cc + dir_c[di];
            
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
            if (is_visited[nr][nc] || maze[nr][nc] == '0') continue;
            
            q.push({nr, nc, cnt + 1});
            is_visited[nr][nc] = true;
        }
    }
    
    return 0;
}
