#include <bits/stdc++.h>

using namespace std;

void solution(int N, int M);
bool canGo(int N, int M, pair<int, int> pos);

const int MAXSIZE = 500;
char graph[MAXSIZE][MAXSIZE] = {};

pair<int, int> Directions[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }

    solution(N, M);

    return 0;
}


void solution(int N, int M)
{
    pair<int, int> next;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (graph[i][j] == 'W')
            {
                for (auto& dir : Directions)
                {
                    next = { i + dir.first , j + dir.second };
                    if (canGo(N, M, next))
                    {
                        if (graph[next.first][next.second] == 'S')
                        {
                            cout << 0;
                            return;
                        }
                    }
                }
            }
        }
    }

    cout << 1 << "\n";
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (graph[i][j] == '.')
                cout << 'D';
            else
                cout << graph[i][j];
        }
        cout << "\n";
    }

}

bool canGo(int N, int M, pair<int, int> pos)
{
    if (pos.first < 0 || N <= pos.first)
        return false;
    if (pos.second < 0 || M <= pos.second)
        return false;

    return true;
}