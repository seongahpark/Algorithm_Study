#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int N, K;
bool visited[MAX + 1];

void BFS()
{
    queue<pair<int, int>> q;
    q.emplace(N, 0);
    visited[N] = true;

    int min_time = -1, cases = 0;

    while (!q.empty())
    {
        int now = q.front().first;
        int time_cnt = q.front().second;
        q.pop();

        visited[now] = true;
        visited[K] = false;

        // ���� ��ġ�� ��ǥ������ ���ٸ�
        if (now == K)
        {
            // �ּҽð��� ã�Ұ� && ���� �ð��� �ּ� �ð��� ���ٸ�
            if (min_time != -1 && time_cnt == min_time)
                // ����� �� + 1
                cases++;

            // �ּҽð��� ã�� ���ߴٸ�
            if (min_time == -1)
            {
                // �ּҽð� = ����ð�
                min_time = time_cnt;
                // ����� �� + 1
                cases++;
            }

            continue;
        }

        int next1 = now - 1;
        int next2 = now + 1;
        int next3 = now * 2;

        if (next1 >= 0 && !visited[next1])
            q.emplace(next1, time_cnt + 1);
        if (next2 <= K && !visited[next2])
            q.emplace(next2, time_cnt + 1);
        if (next3 <= K + 1 && !visited[next3])
            q.emplace(next3, time_cnt + 1);
    }

    cout << min_time << '\n';
    cout << cases;
}

int main()
{
    cin >> N >> K;

    BFS();

    return 0;
}