#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; // �׽�Ʈ���̽�
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int N, M; // ������ ����, �ñ��� ������ �ε���
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        int priority;
        for (int i = 0; i < N; i++)
        {
            cin >> priority;
            q.emplace(priority, i);
            pq.push(priority);
        }

        int cnt = 1;
        while (true)
        {
            if (pq.top() == q.front().first && q.front().second == M)
            {
                cout << cnt << '\n';
                break;
            }
            else if (pq.top() == q.front().first)
            {
                q.pop();
                pq.pop();
                cnt++;
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
    }
}