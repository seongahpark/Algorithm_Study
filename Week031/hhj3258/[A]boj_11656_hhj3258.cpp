#include <bits/stdc++.h>
using namespace std;

void Solve(string S)
{
    vector<string> vec(S.size());
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = i; j < S.size(); j++)
        {
            vec[i] += S[j];
        }
    }

    sort(vec.begin(), vec.end());

    for (auto &item : vec)
    {
        cout << item << '\n';
    }
}

int main()
{
    string S;
    cin >> S;

    Solve(S);
}