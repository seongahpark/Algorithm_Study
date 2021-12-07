#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    unordered_map<int, int> my_map;

    int card = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> card;
        my_map[card]++;
    }

    int M;
    cin >> M;

    int num = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        cout << my_map[num] << ' ';
    }
}