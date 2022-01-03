#include <iostream>
#include <vector>

using namespace std;

void Solve(vector<vector<int>> &A, vector<vector<int>> &B)
{
    // C[A 행렬의 행][B행렬의 열]
    vector<vector<int>> C(A.size(), vector<int>(B[0].size()));

    for (int i = 0; i < C.size(); i++)
        for (int j = 0; j < C[0].size(); j++)
            for (int k = 0; k < A[0].size(); k++)
                C[i][j] += (A[i][k] * B[k][j]);

    for (int i = 0; i < C.size(); i++)
    {
        for (int j = 0; j < C[0].size(); j++)
        {
            cout << C[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    int N, M, K;

    // 행>>열
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    // 행>>열
    cin >> M >> K;
    vector<vector<int>> B(M, vector<int>(K));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            cin >> B[i][j];

    Solve(A, B);
}