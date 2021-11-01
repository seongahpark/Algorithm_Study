#include <bits/stdc++.h>
using namespace std;

int ott[] = {1, 2, 3};
int cnt = 0;

void Solve(int num, int sum)
{
    if (sum >= num)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (sum + ott[i] <= num)
            Solve(num, sum + ott[i]);
    }
}

int main()
{
    int T;
    cin >> T;

    int num;
    vector<int> answer(T);
    for (int i = 0; i < T; i++)
    {
        cin >> num;
        cnt = 0;
        Solve(num, 0);

        answer[i] = cnt;
    }

    for (int i : answer)
        cout << i << '\n';
}