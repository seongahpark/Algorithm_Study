#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int map[501][501];
int arr[501][501];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y){
    if(arr[x][y] != 0) return arr[x][y];
    arr[x][y] = 1;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(map[x][y] < map[nx][ny]) arr[x][y] = max(arr[x][y], dfs(nx, ny) + 1);
    }
    return arr[x][y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ans = max(ans, dfs(i, j));
        }
    }

    cout << ans;
    return 0;
}