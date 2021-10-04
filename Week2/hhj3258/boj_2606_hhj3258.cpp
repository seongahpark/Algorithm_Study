#include <bits/stdc++.h>
using namespace std;

int com_cnt = 0;

void Solve(vector<vector<int>> &map)
{
    vector<int> visited(com_cnt + 1, false);
    queue<int> q;

    // 시작 정점은 무조건 1번 컴퓨터
    q.push(1);
    visited[1] = true;

    int v = 0;
    int cnt = 0;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        cnt++;

        for (int i = 1; i <= com_cnt; i++)
        {
            if (!visited[i])
            {
                if (map[v][i] == 1)
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    // 1번 컴퓨터는 제외하고 출력
    cout << cnt - 1;
}

int main()
{
    cin >> com_cnt;

    int lines = 0; //간선
    cin >> lines;

    vector<vector<int>> map(com_cnt + 1, vector<int>(com_cnt + 1));
    int v1, v2;
    for (int i = 0; i < lines; i++)
    {
        cin >> v1 >> v2;

        map[v1][v2] = 1;
        map[v2][v1] = 1;
    }

    // cout << "0 1 2 3 4 5 6 7" << '\n';
    // for (int i = 0; i < map.size(); i++)
    // {
    //     for (int j = 0; j < map.size(); j++)
    //     {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    Solve(map);
}