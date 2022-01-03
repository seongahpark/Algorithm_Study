#include <iostream>
#include <vector>

using namespace std;

void Solve(int y, int x, int N)
{
    if ((y / N) % 3 == 1 && (x / N) % 3 == 1)
    {
        cout << ' ';
    }
    else
    {
        if (N < 3)
            cout << '*';
        else
            Solve(y, x, N / 3);
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Solve(i, j, N);
        }
        cout << '\n';
    }
}