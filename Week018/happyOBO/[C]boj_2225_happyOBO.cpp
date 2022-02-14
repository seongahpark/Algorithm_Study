#include <bits/stdc++.h>

using namespace std;

void solution(int N, int K);
int DP(int N, int K);

int main(void)
{
    int N, K;
    cin >> N >> K;

    solution(N , K);
}

void solution(int N, int K) {
    cout << DP(N, K);
}


int DP(int N, int K)
{
    vector<vector<int>> acc = vector<vector<int>>(K + 1, vector<int>(N+1,1));

    for (int k = 2; k <= K; k++ )
    {
        for (int n = 1; n <= N; n++)
        {
            acc[k][n] = 0;
            for (int i = 0; i <= n; i++)
            {
                acc[k][n] += acc[k - 1][i];
                acc[k][n] %= 1000000000;
            }

        }
    }

    return acc[K][N];
}