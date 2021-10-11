#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int N, K;
bool visited[MAX + 1];

void BFS()
{
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;

    int now;
    int cnt = 0;
    while (!q.empty())
    {
        now = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (now == K)
            break;

        int next1 = now - 1;
        int next2 = now + 1;
        int next3 = now * 2;

        if (next1 >= 0 && !visited[next1])
        {
            q.push({next1, cnt + 1});
            visited[next1] = true;
        }
        if (next2 <= MAX && !visited[next2])
        {
            q.push({next2, cnt + 1});
            visited[next2] = true;
        }
        if (next3 <= MAX && !visited[next3])
        {
            q.push({next3, cnt + 1});
            visited[next3] = true;
        }
    }

    cout << cnt;
}

int main()
{
    cin >> N >> K;

    BFS();
}