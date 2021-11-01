#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;


int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int N, M, result = 0;

void getMaxNum(int x, int y, int cnt, int curScore,vector<int> *map, vector<bool>* visit) {
    if (cnt == 4) { // 깊이가 4가 되면
        if (result < curScore) result = curScore;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > N || ny > M || visit[nx][ny]) continue;
        visit[nx][ny] = 1;
        getMaxNum(nx, ny, cnt + 1, curScore + map[nx][ny], map,visit);
        visit[nx][ny] = 0; // 백트래킹
    }

    if (x - 1 >= 1 && y - 1 >= 1 && x + 1 <= N) { //ㅓ
        result = max(result, (map[x - 1][y] + map[x][y - 1] + map[x][y] + map[x + 1][y]));
    }
    if (x - 1 >= 1 && y + 1 <= M && x + 1 <= N) { //ㅏ
        result = max(result, (map[x - 1][y] + map[x][y + 1] + map[x][y] + map[x + 1][y]));
    }
    if (y - 1 >= 1 && y + 1 <= M && x + 1 <= N) { //ㅗ
        result = max(result, (map[x][y] + map[x + 1][y] + map[x + 1][y - 1] + map[x + 1][y + 1]));
    }
    if (y - 1 >= 1 && y + 1 <= M && x + 1 <= N) { //ㅜ
        result = max(result, (map[x][y - 1] + map[x][y] + map[x][y + 1] + map[x + 1][y]));
    }

}


int main() {
    cin >> N >> M;
    vector<int>* Tetromino = new vector<int>[N+1]();
    vector<bool>* visit = new vector<bool>[N+1]();
    for (int i = 1; i <= N; i++) {
        Tetromino[i].push_back(0);
        visit[i].push_back(0);
        for (int j = 1; j <= M; j++) {
            int num;
            cin >> num;
            Tetromino[i].push_back(num);
            visit[i].push_back(0);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            visit[i][j] = 1;
            getMaxNum(i, j, 1, Tetromino[i][j],Tetromino, visit);
            visit[i][j] = 0; // 백트래킹
        }
    }
    cout << result;
}

