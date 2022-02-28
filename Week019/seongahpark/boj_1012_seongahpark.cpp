#include <iostream>
#include <cstring> //memset 사용을 위함

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int arr[51][51];
bool visited[51][51];

int t, m, n, k;

//dfs나 bfs를 이용하여 상하좌우의 배추를 확인해주기
void dfs(int x, int y){
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<m){
            if(arr[nx][ny] == 1 && !visited[nx][ny]) dfs(nx, ny);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){ //테스트케이스가 다 할때 까지
        cin >> m >> n >> k;
        int cnt = 0;
        for(int i=0; i<k; i++){
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1; //y, x 순인거 조심
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1 && !visited[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        cout << cnt << "\n";
        memset(visited, false, sizeof(visited));
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}