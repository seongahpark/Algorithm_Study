#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class SegmentTree
{
public:
    SegmentTree(int size) : _dataSize(size)
    {
        _tree.resize(size * 4);
    }

    int GetXXX()
    {
        int sum = 1 + 2;
        return sum;
    }

    int MakeSegmentTree(vector<int> &nums, int node, int rangeStart, int rangeEnd)
    {
        if (rangeStart == rangeEnd)
            return _tree[node] = nums[rangeStart];

        int mid = (rangeStart + rangeEnd) / 2;

        int leftTree = MakeSegmentTree(nums, node * 2, rangeStart, mid);
        int rightTree = MakeSegmentTree(nums, node * 2 + 1, mid + 1, rangeEnd);

        return _tree[node] = min(leftTree, rightTree);
    }

    int GetMinElement(int left, int right)
    {
        return MinElement(left, right, 1, 0, _dataSize - 1);
    }

private:
    int MinElement(int left, int right, int node, int rangeStart, int rangeEnd)
    {
        // case 1 : 범위를 벗어났을 때
        if (rangeStart > right || rangeEnd < left)
            return INT_MAX;

        // case 2 : 범위에 딱 들어맞을 때
        if (rangeStart >= left && rangeEnd <= right)
            return _tree[node];

        // case 3 : 범위에 걸쳐있을 때
        int mid = (rangeStart + rangeEnd) / 2;
        int leftTree = MinElement(left, right, node * 2, rangeStart, mid);
        int rightTree = MinElement(left, right, node * 2 + 1, mid + 1, rangeEnd);

        return min(leftTree, rightTree);
    }

private:
    vector<int> _tree;
    int _dataSize;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    SegmentTree segmentTree(N);
    segmentTree.MakeSegmentTree(nums, 1, 0, N - 1);

    int left, right;
    for (int i = 0; i < M; i++)
    {
        cin >> left >> right;

        int answer = segmentTree.GetMinElement(left - 1, right - 1);
        cout << answer << '\n';
    }
}