#include <bits/stdc++.h>

using namespace std;

const int Size = 100001;

int arr_inOrder[Size];
int arr_postOrder[Size];
unordered_map<int, int> inOrderIdx;

// 중위순회와 후위순회를 가지고 전위순회 출력
void Solve(int inStartIdx, int inEndIdx, int postStartIdx, int postEndIdx)
{
    if (inStartIdx > inEndIdx)
        return;
    if (postStartIdx > postEndIdx)
        return;

    int rootIdx = inOrderIdx[arr_postOrder[postEndIdx]];
    int leftTreeSize = rootIdx - inStartIdx;

    // 전위순회 : 루트 - 좌 - 우
    // 루트 출력 = 후위 순회의 가장 마지막 인덱스
    cout << arr_postOrder[postEndIdx] << ' ';
    // 왼쪽 트리 탐색
    // Solve(그대로, 루트 인덱스 - 1 번째까지, 그대로, 후위순회 시작 인덱스부터 루트 인덱스 이전까지)
    Solve(inStartIdx, rootIdx - 1, postStartIdx, postStartIdx + leftTreeSize - 1);
    // 오른쪽 트리 탐색
    // Solve(루트 인덱스 + 1 번째부터, 그대로, 루트 인덱스부터, 후위순회 마지막 인덱스(루트 인덱스) 이전까지)
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