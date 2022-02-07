// 2467 용액
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

void solution(int N, const vector<long long> &v);
pair<long long, long long> binarySearch(long long number, int minIdx, int maxIdx, const vector<long long> &v);

int main()
{
    int N;
    cin >> N;
    vector<long long> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    solution(N, v);
}

void solution(int N, const vector<long long> &v)
{
    long long sumMin = LLONG_MAX;
    pair<long long, long long> result = make_pair(-1, -1);

    for (int i = 0; i < N; i++)
    {
        auto p = binarySearch(v[i], i + 1, N - 1, v);
        auto addNumber = p.first;
        auto sum = abs(p.second);
        if (sumMin > sum)
        {
            result = {v[i], addNumber};
            sumMin = sum;
        }
    }

    cout << result.first << " " << result.second;

}


pair<long long, long long> binarySearch(long long number, int minIdx, int maxIdx, const vector<long long> &v)
{
    long long sumMin = LLONG_MAX;
    pair<long long, long long> result = {-1, sumMin};

    int midIdx = (minIdx + maxIdx) / 2;
    long long sum = LLONG_MAX;
    while (minIdx <= maxIdx)
    {
        midIdx = (minIdx + maxIdx) / 2;
        sum = number + v[midIdx];

        if(sumMin > abs(sum))
        {
            sumMin = abs(sum);
            result = {v[midIdx], sum};
        }

        if (sum == 0) break;
        else if (sum > 0) maxIdx = midIdx - 1;
        else minIdx = midIdx + 1;
    }

    return result;
}
