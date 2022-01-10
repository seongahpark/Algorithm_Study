#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> coordinates(N);
    for (int i = 0; i < N; i++)
        cin >> coordinates[i].first >> coordinates[i].second;

    sort(coordinates.begin(), coordinates.end(), cmp);

    for (int i = 0; i < N; i++)
        cout << coordinates[i].first << ' ' << coordinates[i].second << '\n';
}