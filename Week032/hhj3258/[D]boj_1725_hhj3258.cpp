#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    SegmentTree(vector<int> height, int size)
        : _height(height), _dataSize(size), _tree(size * 4)
    {
    }

    // 각 세그먼트는 해당 세그먼트 내의 높이의 최솟값 인덱스를 가진다.
    int MakeTree(const vector<int> &height, int node, int rangeStart, int rangeEnd)
    {
        if (rangeStart == rangeEnd)
            return _tree[node] = rangeStart;

        int mid = (rangeStart + rangeEnd) / 2;
        int leftTree = MakeTree(height, node * 2, rangeStart, mid);
        int rightTree = MakeTree(height, node * 2 + 1, mid + 1, rangeEnd);

        // 인덱스를 비교하는게 아니라 해당 인덱스의 '높이'를 비교한다.
        if (height[leftTree] < height[rightTree])
        {
            return _tree[node] = leftTree;
        }
        else
        {
            return _tree[node] = rightTree;
        }
    }

    void GetMaxRectangleArea(int left, int right, int &OUT_Answer)
    {
        if (left > right)
            return;

        int idx = MinHeightIndex(left, right, 1, 0, _dataSize - 1);
        int rectangleArea = _height[idx] * (right - left + 1);

        OUT_Answer = max(OUT_Answer, rectangleArea);

        // 최소 높이를 가진 idx를 제외시키면서 분할정복한다.
        GetMaxRectangleArea(left, idx - 1, OUT_Answer);  // idx 기준 left
        GetMaxRectangleArea(idx + 1, right, OUT_Answer); // idx 기준 right
    }

private:
    int MinHeightIndex(int left, int right, int node, int rangeStart, int rangeEnd)
    {
        if (rangeStart > right || rangeEnd < left)
            return INT_MAX;

        if (rangeStart >= left && rangeEnd <= right)
            return _tree[node];

        int mid = (rangeStart + rangeEnd) / 2;
        int leftTree = MinHeightIndex(left, right, node * 2, rangeStart, mid);
        int rightTree = MinHeightIndex(left, right, node * 2 + 1, mid + 1, rangeEnd);

        // 두 인덱스 중 하나가 배열 범위를 벗어나면 벗어나지 않은 쪽을 return
        if (leftTree == INT_MAX || rightTree == INT_MAX)
        {
            return min(leftTree, rightTree);
        }

        if (_height[leftTree] < _height[rightTree])
        {
            return leftTree;
        }
        else
        {
            return rightTree;
        }
    }

private:
    vector<int> _height;
    vector<int> _tree;
    int _dataSize;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> height(N);
    for (int i = 0; i < N; i++)
    {
        cin >> height[i];
    }

    SegmentTree segmentTree(height, N);
    segmentTree.MakeTree(height, 1, 0, N - 1);

    int answer = -1;
    segmentTree.GetMaxRectangleArea(0, N - 1, answer);
    cout << answer;
}