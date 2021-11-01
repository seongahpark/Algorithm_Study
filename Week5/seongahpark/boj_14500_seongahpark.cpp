#include <iostream>
#include <algorithm>
#define MAX 500
using namespace std;

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

int n, m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int ans;

void h_shape(int y, int x) {
    // ㅜ
	if (y + 1 < n && x + 2 < m) 
        ans = max(ans, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1]);
    // ㅏ
    if (y + 2 < n && x + 1 < m)
        ans = max(ans, arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x]);
    // ㅗ
    if (y - 1 >= 0 && x + 2 < m)
        ans = max(ans, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 1]);
    // ㅓ
    if (y + 2 < n && x - 1 >= 0)
        ans = max(ans, arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 2][x]);
}

// ㅜ모양 외 체크
void n_shape(int L, int sum, int y, int x)
{
    if (L == 3)
    {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (visited[ny][nx])
            continue;
        visited[ny][nx] = true;
        n_shape(L + 1, sum + arr[ny][nx], ny, nx);
        visited[ny][nx] = false;
    }
}

void findAns(int y, int x)
{
    h_shape(y, x);

    visited[y][x] = true;
    n_shape(0, arr[y][x], y, x);
    visited[y][x] = false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            findAns(i, j);
        }
    }

    cout << ans;

	return 0;
}