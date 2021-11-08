#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1001];

void Solve(vector<int> &A)
{
    int max_v = 1;

    for (int i = 0; i < N; i++)
    {
        dp[i] = 1; // �ּ� ���� = 1

        // ���� �� Ž��
        for (int j = 0; j < i; j++)
        {
            // ���� �� > ���� ��
            if (A[i] > A[j])
            {
                // ���� ���� = max(���� ����, ���� ���� + 1)
                dp[i] = max(dp[i], dp[j] + 1);
                // �ְ� ���� = max(�ְ� ����, ���� ����)
                max_v = max(max_v, dp[i]);
            }
        }
    }

    cout << max_v;
}

int main()
{
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solve(A);
}