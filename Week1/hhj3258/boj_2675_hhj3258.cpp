#include <bits/stdc++.h>
using namespace std;

int T;

void Solve(string str, int R)
{
    string answer = "";

    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 0; j < R; j++)
            answer += str[i];
    }

    cout << answer << endl;
}

int main()
{
    cin >> T;

    int R;
    for (int i = 0; i < T; i++)
    {
        string str = "";
        cin >> R >> str;
        Solve(str, R);
    }
}