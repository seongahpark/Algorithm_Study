#include <bits/stdc++.h>

using namespace std;

// 전위 순회를 후위 순회로 변경해서 출력
void Solve(const vector<int> &keys, int nodeIdx, int endIdx)
{
    if (nodeIdx >= endIdx)
        return;

    int rightIdx = nodeIdx + 1;
    for (int i = nodeIdx + 1; i < endIdx; i++)
    {
        if (keys[i] > keys[nodeIdx])
        {
            rightIdx = i;
            break;
        }
    }

    // 후위 순회 (왼쪽-오른쪽-루트)
    // 왼쪽 서브 트리 탐색
    Solve(keys, nodeIdx + 1, rightIdx);
    // 오른쪽 서브 트리 탐색
    Solve(keys, rightIdx, endIdx);

    cout << keys[nodeIdx] << '\n';
}

int main()
{
    int key;
    vector<int> keys;
    while (cin >> key)
    {
        if (key == EOF)
            break;
        keys.push_back(key);
    }

    Solve(keys, 0, keys.size());
}