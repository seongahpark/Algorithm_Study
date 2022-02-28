// 적록색약

#include <bits/stdc++.h>


using namespace std;

void solution(int N);
int countGroups(int N, bool(*canGoFunc)(pair<int, int> curr, pair<int, int> next, int N));
void bfs(pair<int, int> start, const int N, bool(*canGoFunc)(pair<int, int> curr, pair<int, int> next, int N));
bool canGo(pair<int, int> curr, pair<int, int> next, int N);
bool canGoColorBlind(pair<int, int> curr, pair<int, int> next, int N);


pair<int, int> Directions[4] = { {1, 0}, {-1, 0}, {0, 1} , {0, -1} };

const int MAXSIZE = 100;

char graph[MAXSIZE][MAXSIZE] = {};
bool visited[MAXSIZE][MAXSIZE] = {};

int main()
{

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> graph[i][j];

    solution(N);

}


void solution(int N)
{
    int general, colorblind;
    general = countGroups(N, canGo);
    fill(&visited[0][0], &visited[MAXSIZE - 1][MAXSIZE], false);
    colorblind = countGroups(N, canGoColorBlind);
    cout << general << " " << colorblind;
}

int countGroups(int N, bool(*canGoFunc)(pair<int, int> curr, pair<int, int> next, int N))
{
    // 구역 카운트
    int result = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            pair<int, int> curr = { i, j };
            if (!visited[curr.first][curr.second])
            {
                bfs(curr, N, canGoFunc);
                result++;
            }
        }
    return result;
}

void bfs(pair<int,int> start, const int N, bool(*canGoFunc)(pair<int, int> curr, pair<int, int> next, int N))
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
            if (canGoFunc(curr, next, N))
            {
                visited[next.first][next.second] = true;
                q.push(next);
            }
        }
    }
}

// 적록색약 아닌 사람의 비교함수
bool canGo(pair<int, int> curr, pair<int, int> next, int N)
{
    if (next.first < 0 || N <= next.first)
        return false;
    if (next.second < 0 || N <= next.second)
        return false;
    if (graph[next.first][next.second] != graph[curr.first][curr.second])
        return false;

    return !visited[next.first][next.second];
}

// 적록색약인 사람의 비교함수
bool canGoColorBlind(pair<int, int> curr, pair<int, int> next, int N)
{
    if (next.first < 0 || N <= next.first)
        return false;
    if (next.second < 0 || N <= next.second)
        return false;
    if ((graph[next.first][next.second] != graph[curr.first][curr.second]) && 
        (graph[next.first][next.second] == 'B' || graph[curr.first][curr.second] == 'B'))
        return false;

    return !visited[next.first][next.second];
}
