#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    unordered_map<string, int> my_map;

    string name;
    vector<string> answer;
    for (int i = 0; i < N + M; i++)
    {
        cin >> name;
        my_map[name]++;

        if (my_map[name] == 2)
            answer.push_back(name);
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (string str : answer)
        cout << str << '\n';
}