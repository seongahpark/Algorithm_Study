// 양
#include <bits/stdc++.h>

using namespace std;

void solution(int R, int C);
pair<int, int> bfs(pair<int, int> start, const int R, const int C);
bool canGo(pair<int, int> pos, int row, int column);
void calcDiffCurrentField(pair<int, int> pos, pair<int, int>& SheepAndWolfDiff);

enum EField : char
{
    EMPTY = '.',
    FENCE = '#',
    SHEEP = 'o',
    WOLF = 'v',
};

pair<int, int> Directions[4] = { {1, 0}, {-1, 0}, {0, 1} , {0, -1} };

const int MAXSIZE = 250;

EField graph[MAXSIZE][MAXSIZE] = {};
bool visited[MAXSIZE][MAXSIZE] = {};

int main()
{
    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            char c;
            cin >> c;
            graph[i][j] = static_cast<EField>(c);
        }

    solution(R, C);
}


void solution(int R, int C)
{
    // first : 양 second : 늑대 수
    pair<int, int> result = { 0 , 0 };
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            pair<int, int> curr = { i, j };
            if (canGo(curr, R,C))
            {
                pair<int, int> SheepAndWolfDiff = bfs(curr, R, C);
                if (SheepAndWolfDiff.first > SheepAndWolfDiff.second)
                    result.first += SheepAndWolfDiff.first;
                else
                    result.second += SheepAndWolfDiff.second;
            }
        }

    cout << result.first << " " << result.second;
}


pair<int,int> bfs(pair<int,int> start, const int R, const int C)
{
    // first : 양 second : 늑대 수
    pair<int, int> SheepAndWolf = {0,0};
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    calcDiffCurrentField(start, SheepAndWolf);

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        for (auto& dir : Directions)
        {
            pair<int, int> next = { curr.first + dir.first , curr.second + dir.second };
            if (canGo(next, R, C))
            {
                calcDiffCurrentField(next, SheepAndWolf);
                visited[next.first][next.second] = true;
                q.push(next);
            }
        }
    }

    return SheepAndWolf;
}


bool canGo(pair<int, int> pos, int row, int column)
{
    if (pos.first < 0 || row <= pos.first)
        return false;
    if (pos.second < 0 || column <= pos.second)
        return false;
    if (graph[pos.first][pos.second] == FENCE)
        return false;

    return !visited[pos.first][pos.second];
}

/* pos 에서의 필드 값에 따라 SheepAndWolf 파트 증가 first : 양 second : wolf */
void calcDiffCurrentField(pair<int, int> pos, pair<int,int>& SheepAndWolf)
{
    switch (graph[pos.first][pos.second])
    {
    case(SHEEP):
        SheepAndWolf.first++;
        break;
    case(WOLF):
        SheepAndWolf.second++;
        break;
    default:
        break;
    }
}