#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> nums(N);
    set<int> temp_set;
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
        temp_set.insert(nums[i]);
    }

    int cnt = 0;
    vector<int> sorted_nums(temp_set.begin(), temp_set.end());

    for (auto num : nums)
    {
        // find 함수는 선형 탐색이다. 값을 찾을 수 있지만 이 문제에서는 비효율적
        // auto it = find(sorted_nums.begin(), sorted_nums.end(), num);
        // int pos = it - sorted_nums.begin();

        // lower_bound 가 num에 해당하는 값을 찾지 못했다면
        // sorted_nums.end() 를 반환한다.
        int pos = lower_bound(sorted_nums.begin(), sorted_nums.end(), num) - sorted_nums.begin();
        cout << pos << ' ';
    }
}