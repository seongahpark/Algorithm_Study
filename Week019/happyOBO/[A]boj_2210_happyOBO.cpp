// 숫자판 점프

#include <bits/stdc++.h>

using namespace std;

void solution();
void dfs(pair<int, int> curr, string seq);
bool canGo(pair<int, int> pos);

const int SIZE = 5;

int graph[SIZE][SIZE] = {};
vector<string> result;

pair<int, int> Directions[4] = { {1, 0} , {-1, 0}, {0,1}, {0,-1} };

int main()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> graph[i][j];

    solution();
}


void solution()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            dfs({ i,j }, "");
    cout << result.size();
}


void dfs(pair<int,int> curr, string seq)
{
    if (seq.size() == 6) // 5 번 이동 완료
    {
        // 이전에 발견되지 않은 순서면 push
        if (find(result.begin(), result.end(), seq) == result.end())
            result.push_back(seq);
        return;
    }
    else
    {
        for (auto& dir : Directions)
        {
            pair<int, int> next = { curr.first + dir.first , curr.second + dir.second };
            if(canGo(next))
                dfs(next, seq + to_string(graph[next.first][next.second]));
        }
    }
}


bool canGo(pair<int, int> pos)
{
    if (pos.first < 0 || SIZE <= pos.first)
        return false;
    if (pos.second < 0 || SIZE <= pos.second)
        return false;

    return true;
}