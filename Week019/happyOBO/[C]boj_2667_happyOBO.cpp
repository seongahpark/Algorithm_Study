// 단지번호붙이기

#include <bits/stdc++.h>

using namespace std;

void solution(int N);
int bfs(pair<int, int> start, const int N);
bool canGo(pair<int, int> pos, int N);

enum EField : char
{
    EMPTY = '0',
    HOME = '1',
};

pair<int, int> Directions[4] = { {1, 0}, {-1, 0}, {0, 1} , {0, -1} };

const int MAXSIZE = 25;

EField graph[MAXSIZE][MAXSIZE] = {};
bool visited[MAXSIZE][MAXSIZE] = {};

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            char c;
            cin >> c;
            graph[i][j] = static_cast<EField>(c);
        }

    solution(N);
}


void solution(int N)
{
    vector<int> result;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            pair<int, int> curr = { i, j };
            if (canGo(curr, N))
            {
                result.push_back(bfs(curr, N));
            }
        }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for_each(result.begin(), result.end(), [](int x) {cout << x << "\n"; });
}


int bfs(pair<int,int> start, const int N)
{
    // bfs 를 통한 면적 개수 카운트
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    cnt++;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        for (auto& dir : Directions)
        {
            pair<int, int> next = { curr.first + dir.first , curr.second + dir.second };
            if (canGo(next, N))
            {
                visited[next.first][next.second] = true;
                q.push(next);
                cnt++;
            }
        }
    }

    return cnt;
}


bool canGo(pair<int, int> pos, int N)
{
    if (pos.first < 0 || N <= pos.first)
        return false;
    if (pos.second < 0 || N <= pos.second)
        return false;
    if (graph[pos.first][pos.second] == EMPTY)
        return false;

    return !visited[pos.first][pos.second];
}
