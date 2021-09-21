#include <bits/stdc++.h>
using namespace std;

string num;

void Solve()
{
    int answer = 0;
    for (int i = 0; i < num.size(); i++)
        answer += num[i] - '0';

    cout << answer;
}

int main()
{
    int N = 0;
    cin >> N >> num;
    Solve();
}