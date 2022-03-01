#include <iostream>
#include <cstring> //memset

using namespace std;

int n, cnt = 0;
char arr[101][101];
bool visited[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx >= 0 && ny >= 0 && nx < n && ny < n){
            if(!visited[nx][ny] && arr[x][y] == arr[nx][ny]){
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    //적록 색약이 아닌 사람
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;

    //적록 색약인 사람
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 'G') arr[i][j] = 'R';
        }
    }

    memset(visited, false, sizeof(visited));

    cnt = 0;
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << " " << cnt;
    return 0;
}