#include <iostream>
#include <queue>

using namespace std;
const int MAX = 251;

int r, c, t_w, t_s;
char arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


//모든 정점에서 방문하지 않은 곳에 한해 bfs를 돌려본다
//bfs 안에 늑대와 양의 개수를 세는 w, s 변수를 넣어줌
//끝날 시점에 늑대와 양의 수를 비교해준다
void bfs(int a, int b){
    int w = 0, s = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    visited[a][b] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(arr[x][y] == 'v') w++;
        if(arr[x][y] == 'o') s++;

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny= y+dy[i];

            if(nx>=0 && ny >= 0 && nx <r && ny < c){
                if(arr[nx][ny] != '#' && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    if(s > w) t_s += s;
    else t_w += w;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!visited[i][j]) bfs(i, j);
        }
    }

    cout << t_s << " " << t_w;
    return 0;
}