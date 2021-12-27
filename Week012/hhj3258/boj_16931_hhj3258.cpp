#include <bits/stdc++.h>
using namespace std;

int N, M;

void Solve(vector<vector<int>> &box)
{
    // 포인트는 왼쪽면이든 오른쪽 면이든 넓이는 같다는 것.
    // 3차원을 2차원으로 투영해서 생각하면 된다.

    // 윗면, 아랫면
    int up = N * M;
    up *= 2;

    // 앞면, 뒷면
    int front = 0;
    for (int i = 0; i < N; i++)
        front += box[i][0];

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            if (box[i][j] > box[i][j - 1])
                front += box[i][j] - box[i][j - 1];
        }
    }
    front *= 2;

    // 왼쪽면, 오른쪽면
    int left = 0;
    for (int i = 0; i < M; i++)
        left += box[0][i];

    for (int n = 1; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            if (box[n][m] > box[n - 1][m])
                left += box[n][m] - box[n - 1][m];
        }
    }
    left *= 2;

    int answer = up + front + left;
    cout << answer;
}

int main()
{
    cin >> N >> M;

    vector<vector<int>> box(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> box[i][j];

    Solve(box);
}