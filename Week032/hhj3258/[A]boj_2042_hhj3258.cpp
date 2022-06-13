#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    SegmentTree(int arrSize) : N(arrSize)
    {
        tree.resize(arrSize * 4);
    }

    long long MakeSegmentTree(vector<long long> &nums, int node, int leftNode, int rightNode)
    {
        // left~right 구간이 1이라면 즉, 리프 노드에 도달했다면
        if (leftNode == rightNode)
            return tree[node] = nums[leftNode];

        // left~right 구간이 1보다 크다면
        int mid = (leftNode + rightNode) / 2;

        return tree[node] = MakeSegmentTree(nums, node * 2, leftNode, mid) + MakeSegmentTree(nums, node * 2 + 1, mid + 1, rightNode);
    }

    long long GetPrefixSum(int left, int right)
    {
        return PrefixSum(left, right, 1, 0, N - 1);
    }

    void Update(int index, long long newValue)
    {
        UpdateTree(index, newValue, 1, 0, N - 1);
    }

    void PrintTree(int left, int right, int node)
    {
        int level = 1;
        int size = 1;
        int cnt = 1;
        while (true)
        {
            cout << "Level " << level << endl;

            for (int i = 0; i < size; i++)
            {
                if (node + i >= tree.size())
                    return;
                cout << tree[node + i] << ' ';
                // cout << node + i << ' ';
            }
            cout << "\n\n";

            node = node * 2;
            level++;
            size = pow(2, cnt++);
        }
    }

private:
    long long PrefixSum(int left, int right, int node, int rangeStart, int rangeEnd)
    {
        // case 1 : 현재 세그먼트가 범위를 완벽하게 벗어났을 때
        if (rangeStart > right || rangeEnd < left)
            return 0;

        // case 2 : 현재 세그먼트가 딱 들어맞을 때
        if (rangeStart >= left && rangeEnd <= right)
            return tree[node];

        // case 3 : 현재 세그먼트가 완벽히 들어맞지는 않았을 때
        int mid = (rangeStart + rangeEnd) / 2;

        return PrefixSum(left, right, node * 2, rangeStart, mid) + PrefixSum(left, right, node * 2 + 1, mid + 1, rangeEnd);
    }

    long long UpdateTree(int index, long long newValue, int node, int rangeStart, int rangeEnd)
    {
        if (rangeStart > index || rangeEnd < index)
            return tree[node];

        if (rangeStart == rangeEnd)
            return tree[node] = newValue;

        int mid = (rangeStart + rangeEnd) / 2;

        return tree[node] = UpdateTree(index, newValue, node * 2, rangeStart, mid) + UpdateTree(index, newValue, node * 2 + 1, mid + 1, rangeEnd);
    }

private:
    int N;
    vector<long long> tree;
};

int main()
{
    // N : 수의 개수, M : 수의 변경이 일어나는 횟수, K : 구간의 합을 구하는 횟수
    int N, M, K;
    cin >> N >> M >> K;

    // 2줄부터 N+1 줄까지 N개의 수가 주어진다.
    vector<long long> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    SegmentTree segmentTree(N);
    segmentTree.MakeSegmentTree(nums, 1, 0, N - 1);

    // a=1 인 경우 b번째 수를 c로 바꾼다.
    // a=2 인 경우 b번째 수부터 c번째 수까지의 합을 구하고 출력한다.
    int a, b;
    long long c;
    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            segmentTree.Update(b - 1, c);
        }
        else if (a == 2)
        {
            long long sum = segmentTree.GetPrefixSum(b - 1, c - 1);
            cout << sum << '\n';
        }
    }
}