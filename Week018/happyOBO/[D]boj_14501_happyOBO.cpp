#include <bits/stdc++.h>


using namespace std;

void solution(int N);
int dp(int N);

int times[16] = {};
int prices[16] = {};
vector<int> acc(16, 0);

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> times[i] >> prices[i];
        acc[i] = prices[i];
    }
    solution(N);
}


void solution(int N)
{
    cout << dp(N);
}

int dp(int N)
{
    for (int curr = 1; curr < N; curr++)
    {

        for (int prev = 0; prev < curr; prev++)
        {
            if (times[prev] + prev <= curr)
            {
                acc[curr] = max(prices[curr] + acc[prev], acc[curr]);
            }
        }
    }

    int result = 0;
    for (int day = 0; day < N; day++)
    {
        if (day + times[day] <= N)
            result = max(result, acc[day]);
    }

    return result;
}
