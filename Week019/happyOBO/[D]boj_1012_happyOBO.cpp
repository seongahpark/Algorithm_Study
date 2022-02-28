// 유기농 배추

#include <bits/stdc++.h>


using namespace std;

void solution(int M, int N);
void bfs(pair<int, int> start, const int M, const int N);
bool canGo(pair<int, int> pos, int M, int N);


pair<int, int> Directions[4] = { {1, 0}, {-1, 0}, {0, 1} , {0, -1} };

const int MAXSIZE = 50;

vector<vector<bool>> graph; // false : empty, true : planted
vector<vector<bool>> visited;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N, K;
        cin >> M >> N >> K;
        graph = vector<vector<bool>>(N, vector<bool>(M, false));
        visited = vector<vector<bool>>(N, vector<bool>(M, false));
        for (int k = 0; k < K; k++)
        {
            int x, y;
            cin >> x >> y;
            graph[y][x] = true;
        }

        solution(M,N);
    }
}


void solution(int M, int N)
{
    // 그룹 개수 카운트
    int result = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            pair<int, int> curr = { i, j };
            if (canGo(curr, M, N))
            {
                bfs(curr, M, N);
                result++;
            }
        }


    cout << result << "\n";
}


void bfs(pair<int,int> start, const int M, const int N)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        for (auto& dir : Directions)
        {
            pair<int, int> next = { curr.first + dir.first , curr.second + dir.second };
            if (canGo(next, M, N))
            {
                visited[next.first][next.second] = true;
                q.push(next);
            }
        }
    }
}


bool canGo(pair<int, int> pos, int M, int N)
{
    if (pos.first < 0 || N <= pos.first)
        return false;
    if (pos.second < 0 || M <= pos.second)
        return false;
    if (!graph[pos.first][pos.second])
        return false;

    return !visited[pos.first][pos.second];
}
