#include <bits/stdc++.h>

using namespace std;

const int Size = 100001;

int arr_inOrder[Size];
int arr_postOrder[Size];
unordered_map<int, int> inOrderIdx;

// 전위순회
void Solve(int inStartIdx, int inEndIdx, int postStartIdx, int postEndIdx)
{
    if (inStartIdx > inEndIdx)
        return;
    if (postStartIdx > postEndIdx)
        return;

    int rootIdx = inOrderIdx[arr_postOrder[postEndIdx]];
    int leftTreeSize = rootIdx - inStartIdx;

    // 전위순회 : 루트 - 좌 - 우
    // 루트 출력
    cout << arr_postOrder[rootIdx] << ' ';
    // 왼쪽 트리 탐색
    Solve(inStartIdx, rootIdx - 1, postStartIdx, postStartIdx + leftTreeSize - 1);
    // 오른쪽 트리 탐색
    Solve(rootIdx + 1, inEndIdx, postStartIdx + leftTreeSize, postEndIdx - 1);
}

int main()
{
    int n;
    // 정점의 갯수
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr_inOrder[i];
        inOrderIdx[arr_inOrder[i]] = i;
    }

    for (int i = 0; i < n; i++)
        cin >> arr_postOrder[i];

    Solve(0, n - 1, 0, n - 1);
}