#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main()
{
    int N;
    cin >> N;

    unordered_map<string, int> my_map;

    string book_name;
    for (int i = 0; i < N; i++)
    {
        cin >> book_name;
        my_map[book_name]++;
    }

    vector<pair<string, int>> vec(my_map.begin(), my_map.end());

    sort(vec.begin(), vec.end(), cmp);

    cout << vec[0].first;
}