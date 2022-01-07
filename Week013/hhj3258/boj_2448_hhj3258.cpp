#include <bits/stdc++.h>
using namespace std;

void Draw(vector<vector<char>> &stars, int row, int col)
{
    // line 1
    stars[row][col] = '*';

    // line 2
    stars[row + 1][col - 1] = '*';
    stars[row + 1][col + 1] = '*';

    // line 3
    for (int i = 0; i < 5; i++)
        stars[row + 2][col - 2 + i] = '*';
}

void Solve(vector<vector<char>> &stars, int len, int row, int col)
{
    if (len == 3)
    {
        Draw(stars, row, col);
        return;
    }

    // 삼각형 1 꼭짓점 = [row, col]
    Solve(stars, len / 2, row, col);
    // 삼각형 1 꼭짓점 = [row + (len / 2), col - (len / 2)]
    Solve(stars, len / 2, row + (len / 2), col - (len / 2));
    // 삼각형 1 꼭짓점 = [row + (len / 2), col + (len / 2)]
    Solve(stars, len / 2, row + (len / 2), col + (len / 2));
}

int main()
{
    int N;
    cin >> N;

    vector<vector<char>> stars(N, vector<char>(N * 2 - 1, ' '));

    Solve(stars, N, 0, N - 1);

    for (int i = 0; i < stars.size(); i++)
    {
        for (int j = 0; j < stars[i].size(); j++)
            cout << stars[i][j];
        cout << '\n';
    }
}