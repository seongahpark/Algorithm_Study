#include <bits/stdc++.h>

using namespace std;

void Solve(int N, priority_queue<int, vector<int>, greater<int>> &pq)
{
    int answer = 0;
    int sum = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        answer += sum;
        pq.pop();
    }

    cout << answer;
}

int main()
{
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    int t;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        pq.push(t);
    }

    Solve(N, pq);
}