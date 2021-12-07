#include <bits/stdc++.h>
using namespace std;

int N, M;

void NextLoop(long long &s, long long &e, int &temp_sum)
{
    s++;
    e = s;
    temp_sum = 0;
}

void Solve(vector<int> A)
{
    long long s = 0, e = 0;
    int answer = 0;
    int temp_sum = 0;

    while (s < N && e < N)
    {
        temp_sum += A[e];

        if (temp_sum == M)
        {
            answer++;
            NextLoop(s, e, temp_sum);
        }
        else if (temp_sum > M)
            NextLoop(s, e, temp_sum);
        else
            e++;

        if (e == N)
            NextLoop(s, e, temp_sum);
    }

    cout << answer;
}

int main()
{
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solve(A);
}