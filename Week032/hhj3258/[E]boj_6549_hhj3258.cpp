#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    SegmentTree(vector<long long> &height, int size) : _height(height), _tree(size * 4), _dataSize(size)
    {
    }

    int MakeTree(int node, int rangeStart, int rangeEnd)
    {
        if (rangeStart == rangeEnd)
        {
            // 현재 높이값의 인덱스 저장
            return _tree[node] = rangeStart;
        }

        int mid = (rangeStart + rangeEnd) / 2;
        int leftTree = MakeTree(node * 2, rangeStart, mid);
        int rightTree = MakeTree(node * 2 + 1, mid + 1, rangeEnd);

        if (_height[leftTree] < _height[rightTree])
        {
            return _tree[node] = leftTree;
        }
        else
        {
            return _tree[node] = rightTree;
        }
    }

    void GetMaxRectangleArea(int left, int right, long long &answer)
    {
        if (left > right)
            return;

        int idx = GetMinHeightIndex(left, right, 1, 0, _dataSize - 1);
        long long area = _height[idx] * (right - left + 1);
        answer = max(answer, area);

        GetMaxRectangleArea(left, idx - 1, answer);
        GetMaxRectangleArea(idx + 1, right, answer);
    }

    // 구간 내에서 가장 작은 높이의 인덱스를 구하고 그 인덱스를 중심으로 왼쪽, 오른쪽으로 분할하여
    // 재귀적으로 탐색하면서 해당 재귀에서 가장 큰 직사각형 넓이를 반환한다.
    long long GetMaxRectangleArea(int left, int right)
    {
        int idx = GetMinHeightIndex(left, right, 1, 0, _dataSize - 1);
        long long area = _height[idx] * (right - left + 1);

        if (left <= idx - 1)
        {
            long long leftArea = GetMaxRectangleArea(left, idx - 1);
            area = max(area, leftArea);
        }
        if (idx + 1 <= right)
        {
            long long rightArea = GetMaxRectangleArea(idx + 1, right);
            area = max(area, rightArea);
        }

        return area;
    }

private:
    int GetMinHeightIndex(int left, int right, int node, int rangeStart, int rangeEnd)
    {
        if (rangeStart > right || rangeEnd < left)
            return INT_MAX;

        if (rangeStart >= left && rangeEnd <= right)
            return _tree[node];

        int mid = (rangeStart + rangeEnd) / 2;
        int leftTree = GetMinHeightIndex(left, right, node * 2, rangeStart, mid);
        int rightTree = GetMinHeightIndex(left, right, node * 2 + 1, mid + 1, rangeEnd);

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
    vector<long long> _height;
    vector<int> _tree;
    int _dataSize;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        vector<long long> height(n);
        for (int i = 0; i < n; i++)
            cin >> height[i];

        SegmentTree segmentTree(height, n);
        segmentTree.MakeTree(1, 0, n - 1);

        long long answer = segmentTree.GetMaxRectangleArea(0, n - 1);
        cout << answer << '\n';
    }
}