#include <bits/stdc++.h>

using namespace std;

void dfs(int idx, int length, int S);
bool CanGroup(int start);
bool CanGo(pair<int, int> pos);

const int MAXSIZE = 5;
char graph[MAXSIZE][MAXSIZE] = {};
bool visited[MAXSIZE][MAXSIZE] = {};
bool group[MAXSIZE][MAXSIZE] = {};
int counter = 0;

pair<int, int> Directions[4] = { {1, 0},{0, 1}, {-1,0 } , {0,-1} };



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < MAXSIZE; i++)
    {
        for (int j = 0; j < MAXSIZE; j++)
        {
            cin >> graph[i][j];
        }
    }

    dfs(0, 0, 0);

    

    cout << counter;

    return 0;
}


void dfs(int idx, int length, int S)
{
    if (length == 7)
    {
        if(4 <= S && CanGroup(idx))
            counter++;
    }

    int r, c;
    for (int i = idx; i < 25; i++)
    {
        r = i / 5;
        c = i % 5;
        if (visited[r][c]) continue;
        visited[r][c] = true;
        if (graph[r][c] == 'S')
            dfs(i, length + 1, S + 1);
        else
            dfs(i, length + 1, S);
        visited[r][c] = false;
    }

}


bool CanGroup(int start)
{
    fill(&group[0][0], &group[MAXSIZE - 1][MAXSIZE], false);
    int cnt = 0, r = start / 5, c = start % 5;
    queue <pair<int,int>> q;
    q.push({ r,c });
    group[r][c] = true;
    cnt++;

    pair<int, int> curr, next;
    while (!q.empty())
    {
        curr = q.front(); q.pop();
        
        for (auto& dir : Directions)
        {
            next = { curr.first + dir.first , curr.second + dir.second };
            if (CanGo(next))
            {
                q.push(next);
                group[next.first][next.second] = true;
                cnt++;
            }
        }
    }

    return 7 == cnt;
}


bool CanGo(pair<int, int> pos)
{
    if (pos.first < 0 || MAXSIZE <= pos.first)
        return false;
    if (pos.second < 0 || MAXSIZE <= pos.second)
        return false;
    if (!visited[pos.first][pos.second])
        return false;
    return !group[pos.first][pos.second];
}