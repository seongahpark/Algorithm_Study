#include <bits/stdc++.h>

using namespace std;

enum class Color;
void solution(int N);
long long DP(int N);

int main(void)
{
    int N;
    cin >> N;

    solution(N);
}

void solution(int N) {
    cout << DP(N);
}


long long DP(int N)
{
    // first : even , second : odd
    vector<pair<long long, long long>> acc = vector<pair<long long, long long>>(N + 1);
    acc[1] = { 0 , 1 }; // 1 한개

    for (int i = 2; i <= N; i++)
    {
        acc[i] = { acc[i - 1].first + acc[i - 1].second, acc[i - 1].first };
    }

    return acc[N].first + acc[N].second;
}