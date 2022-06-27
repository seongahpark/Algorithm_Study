#include <iostream>
#include <cstring>

using namespace std;

int N, M, ans;
int arr[501][501];
char map[501][501];

int dx[] = { 0, 0, 1, -1};
int dy[] = { 1, -1, 0, 0};

int chk(char a){
    if(a == 'U') return 3;
    else if(a == 'R') return 0;
    else if(a == 'D') return 2;
    else if(a == 'L') return 1;
}

int dfs(int x, int y){
    if (x < 0 || y < 0 || x >= N || y >= M) return 1;
    if(arr[x][y] != -1) return arr[x][y];

    arr[x][y] = 0;
    int dir = chk(map[x][y]);

    arr[x][y] = dfs(x + dx[dir], y + dy[dir]);

    return arr[x][y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            arr[i][j] = -1;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            ans += dfs(i, j);
        }
    }

    cout << ans;
    return 0;
}