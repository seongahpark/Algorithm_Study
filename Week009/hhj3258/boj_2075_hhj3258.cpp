#include <bits/stdc++.h>

using namespace std;

void Solve(const int *N)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int num;
    for (int i = 0; i < (*N * *N); i++)
    {
        cin >> num;
        pq.push(num);

        if (pq.size() > *N)
        {
            pq.pop();
        }
    }

    cout << pq.top();
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    Solve(&N);
}