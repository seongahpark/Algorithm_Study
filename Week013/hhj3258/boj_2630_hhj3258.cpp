#include <iostream>
#include <vector>
using namespace std;

#define WHITE 0
#define BLUE 1

int blue_paper = 0;
int white_paper = 0;

void Solve(vector<vector<int>> &paper, int y, int x, int N)
{
    int blue_cnt = 0;
    for (int i = y; i < (N + y); i++)
    {
        for (int j = x; j < (N + x); j++)
        {
            if (paper[i][j] == BLUE)
                blue_cnt++;
        }
    }

    if (blue_cnt == (N * N))
        blue_paper++;
    else if (blue_cnt == 0)
        white_paper++;
    else
    {
        // 1사분면
        Solve(paper, y, x, N / 2);
        // 2사분면
        Solve(paper, y, x + (N / 2), N / 2);
        // 3사분면
        Solve(paper, y + (N / 2), x, N / 2);
        // 4사분면
        Solve(paper, y + (N / 2), x + (N / 2), N / 2);
    }
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> paper(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    Solve(paper, 0, 0, N);

    cout << white_paper << '\n';
    cout << blue_paper << '\n';
}