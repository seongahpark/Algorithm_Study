#include <bits/stdc++.h>
using namespace std;

int N;

int Check(const vector<string> &candy)
{
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int cnt = 1;
        for (int j = 0; j < N - 1; j++)
        {
            if (candy[i][j] == candy[i][j + 1])
            {
                cnt++;
            }
            else
            {
                answer = max(answer, cnt);
                cnt = 1;
            }
        }
        answer = max(answer, cnt);

        cnt = 1;
        for (int j = 0; j < N - 1; j++)
        {
            if (candy[j][i] == candy[j + 1][i])
            {
                cnt++;
            }
            else
            {
                answer = max(answer, cnt);
                cnt = 1;
            }
        }
        answer = max(answer, cnt);
    }

    return answer;
}

void Solve(vector<string> &candy)
{
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            swap(candy[i][j], candy[i][j + 1]);
            answer = max(answer, Check(candy));
            swap(candy[i][j], candy[i][j + 1]);

            swap(candy[j][i], candy[j + 1][i]);
            answer = max(answer, Check(candy));
            swap(candy[j][i], candy[j + 1][i]);
        }
    }

    cout << answer;
}

int main()
{
    cin >> N;

    vector<string> candy(N);
    for (int i = 0; i < N; i++)
        cin >> candy[i];

    Solve(candy);
}