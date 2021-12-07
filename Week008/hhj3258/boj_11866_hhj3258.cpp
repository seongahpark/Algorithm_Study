#include <bits/stdc++.h>
using namespace std;

int N, K;

void Solve(queue<int> &q)
{
    queue<int> answer;

    int cnt = 1;
    while (!q.empty())
    {
        if (cnt == K)
        {
            answer.push(q.front());
            cnt = 1;
        }
        else
        {
            q.push(q.front());
            cnt++;
        }

        q.pop();
    }

    cout << "<";
    while (!answer.empty())
    {
        if (answer.size() > 1)
            cout << answer.front() << ", ";
        else
            cout << answer.front();

        answer.pop();
    }
    cout << ">";
}

int main()
{
    cin >> N >> K;

    queue<int> q;
    for (int i = 1; i <= N; i++)
        q.push(i);

    Solve(q);
}