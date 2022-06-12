#include <bits/stdc++.h>
using namespace std;

const static int MOD_VALUE = 1000000007;

class SegmentTree
{
public:
    SegmentTree(int size) : _dataSize(size), _tree(size * 4)
    {
    }

    long long MakeTree(const vector<int> &nums, int node, int rangeStart, int rangeEnd)
    {
        if (rangeStart == rangeEnd)
            return _tree[node] = nums[rangeStart];

        int mid = (rangeStart + rangeEnd) / 2;
        long long leftTree = MakeTree(nums, node * 2, rangeStart, mid);
        long long rightTree = MakeTree(nums, node * 2 + 1, mid + 1, rangeEnd);

        return _tree[node] = (leftTree * rightTree) % MOD_VALUE;
    }

    void Update(int idx, int newValue)
    {
        UpdateTree(idx, newValue, 1, 0, _dataSize - 1);
    }

    long long GetRangeMultiply(int left, int right)
    {
        return RangeMultiply(left, right, 1, 0, _dataSize - 1);
    }

private:
    long long UpdateTree(int idx, int newValue, int node, int rangeStart, int rangeEnd)
    {
        if (rangeStart > idx || rangeEnd < idx)
            return _tree[node];

        if (rangeStart == rangeEnd)
            return _tree[node] = newValue;

        int mid = (rangeStart + rangeEnd) / 2;
        long long leftTree = UpdateTree(idx, newValue, node * 2, rangeStart, mid);
        long long rightTree = UpdateTree(idx, newValue, node * 2 + 1, mid + 1, rangeEnd);

        return _tree[node] = (leftTree * rightTree) % MOD_VALUE;
    }

    long long RangeMultiply(int left, int right, int node, int rangeStart, int rangeEnd)
    {
        if (rangeStart > right || rangeEnd < left)
            return 1;

        if (rangeStart >= left && rangeEnd <= right)
            return _tree[node];

        int mid = (rangeStart + rangeEnd) / 2;
        long long leftTree = RangeMultiply(left, right, node * 2, rangeStart, mid);
        long long rightTree = RangeMultiply(left, right, node * 2 + 1, mid + 1, rangeEnd);

        return (leftTree * rightTree) % MOD_VALUE;
    }

private:
    vector<long long> _tree;
    int _dataSize;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // N 수의 개수
    // M 수의 변경이 일어나는 횟수
    // K 구간의 곱을 구하는 횟수
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    SegmentTree segmentTree(N);
    segmentTree.MakeTree(nums, 1, 0, N - 1);

    int a, b, c;
    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;

        // b 번째 수를 c로 바꾼다
        if (a == 1)
        {
            segmentTree.Update(b - 1, c);
        }
        // b 번째부터 c 번째까지의 곱을 구하고 출력
        else if (a == 2)
        {
            int answer = segmentTree.GetRangeMultiply(b - 1, c - 1);
            cout << answer << '\n';
        }
    }
}