#include <bits/stdc++.h>
using namespace std;

static const int MAX = 1001;

void Solve(vector<int> &nums)
{
    vector<bool> isPrime(MAX, true);
    isPrime[0] = false;
    isPrime[1] = false;

    // 0,1 은 소수가 아니므로 2부터 탐색
    for (int i = 2; i * i < MAX; i++)
    {
        // i 가 소수라면, i 의 배수는 모두 i 를 약수로 가지고 있으므로 소수가 아님
        // i 가 소수가 아니라면, 이미 i 를 포함한 i 의 배수는 모두 소수가 아닌 것으로 체크되어 있음
        if (isPrime[i])
        {
            // i^2 부터 탐색하는 이유 : 이미 그 이전 값까지는 검사되었음.
            for (int j = i * i; j < MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (isPrime[nums[i]])
        {
            answer++;
        }
    }

    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    Solve(nums);
}