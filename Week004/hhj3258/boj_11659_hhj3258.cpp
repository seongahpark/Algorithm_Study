#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    // 수의 개수 >> 합을 구해야 하는 횟수
    cin >> N >> M;

    // 원소들
    vector<int> nums(N);
    // 누적 합
    vector<int> sums(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
        sums[i + 1] = sums[i] + nums[i];
    }

    // 합을 구해야 하는 구간
    vector<pair<int, int>> sections(M);
    int left, right;
    for (int i = 0; i < M; i++)
    {
        cin >> left >> right;
        cout << sums[right] - sums[left - 1] << '\n';
    }
}