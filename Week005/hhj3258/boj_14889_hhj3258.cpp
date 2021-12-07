#include <bits/stdc++.h>
using namespace std;

int N;
bool visited[21];
int min_v = INT_MAX;
int people[21][21];

void Solve(int idx, int cnt)
{
    if (cnt == N / 2)
    {
        int team_a = 0, team_b = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i] && visited[j])
                    team_a += people[i][j];
                if (!visited[i] && !visited[j])
                    team_b += people[i][j];
            }
        }

        if (abs(team_a - team_b) < min_v)
            min_v = abs(team_a - team_b);

        return;
    }

    for (int i = idx; i < N; i++)
    {
        if (min_v == 0)
            return;

        if (!visited[i])
        {
            visited[i] = true;
            Solve(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> people[i][j];

    Solve(0, 0);

    cout << min_v;
}