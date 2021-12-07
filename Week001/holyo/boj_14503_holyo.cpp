#include <iostream>
#include <vector>

using namespace std;

const int N = 0, E = 1, S = 2, W = 3;
const int EMPTY = 0, WALL = 1, CLEAN = 2;

int dr[] = { -1, 0, 1, 0 }; // N, E, S, W;
int dc[] = { 0, 1, 0, -1 };

int main() {
    int r, c;
    int sr, sc, sd; // start
    
    cin >> r >> c;
    cin >> sr >> sc >> sd;
    
    int place[r][c];
    
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            cin >> place[ri][ci];
        }
    }
    
    int cnt = 1;
    int cr = sr, cc = sc, cd = sd; // current
    
    place[cr][cc] = CLEAN;
    
    while (true) {
        bool exist = false;
        
        for (int di = 0; di < 4; di++) {
            cd = (cd + 3) % 4;
            
            int nr = cr + dr[cd], nc = cc + dc[cd];
            
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
            if (place[nr][nc] != EMPTY) continue;
            
            exist = true;
            place[nr][nc] = CLEAN;
            cnt++;
            cr = nr;
            cc = nc;
            
            break;
        }
        
        if (!exist) {
            int nd = (cd + 2) % 4;
            cr += dr[nd];
            cc += dc[nd];
            
            if (cr < 0 || cr >= r || cc < 0 || cc >= c || place[cr][cc] == WALL) {
                cout << cnt << '\n';
                
                return 0;
            }
        }
    }
    
    return 0;
}
