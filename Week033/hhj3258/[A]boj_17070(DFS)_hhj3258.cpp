#include <bits/stdc++.h>
using namespace std;

int N;
int answer = 0;

enum class PIPE
{
    HORIZONTAL,
    VERTICAL,
    DIAGONAL,
};

void Solve(vector<vector<int>> &house, int y, int x, PIPE direction)
{
    if (y == N - 1 && x == N - 1)
    {
        answer++;
        return;
    }

    if (y + 1 < N && x + 1 < N)
        if (house[y + 1][x] == 0 && house[y][x + 1] == 0 && house[y + 1][x + 1] == 0)
            Solve(house, y + 1, x + 1, PIPE::DIAGONAL);

    if (direction == PIPE::HORIZONTAL)
    {
        if (x + 1 < N && house[y][x + 1] == 0)
            Solve(house, y, x + 1, PIPE::HORIZONTAL);
    }
    else if (direction == PIPE::VERTICAL)
    {
        if (y + 1 < N && house[y + 1][x] == 0)
            Solve(house, y + 1, x, PIPE::VERTICAL);
    }
    else if (direction == PIPE::DIAGONAL)
    {
        if (x + 1 < N && house[y][x + 1] == 0)
            Solve(house, y, x + 1, PIPE::HORIZONTAL);

        if (y + 1 < N && house[y + 1][x] == 0)
            Solve(house, y + 1, x, PIPE::VERTICAL);
    }
}

int main()
{
    cin >> N;

    vector<vector<int>> house(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> house[i][j];

    Solve(house, 0, 1, PIPE::HORIZONTAL);
    cout << answer;
}