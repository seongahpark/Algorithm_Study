#include <iostream>

using namespace std;

int Index[100001];
int Inorder[100001];
int Postorder[100001];

//전위 순회 구하기
void Preorder(int inStart, int inEnd, int postStart, int postEnd)
{
    // 더 이상 분할 할 수 없는 경우 return
    if (inStart > inEnd || postStart > postEnd)
        return;
    // 후위 순회의 끝 값이 root값
    int rootIndex = Index[Postorder[postEnd]];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;
    cout << Inorder[rootIndex] << ' '; // root 값 출력

    // 재귀 함수 호출
    //중위 순회를 기준으로 구한 루트 노드 기준 3분할 재귀
    Preorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    Preorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    //정점의 갯수
    int n;
    cin >> n;
    
    //중위순회 결과 저장
    for (int i = 1; i <= n; i++){
        cin >> Inorder[i];
        Index[Inorder[i]] = i; // inorder 요소들의 Index 정보 저장
    }
    //후위 순회 결과 저장
    for (int i = 1; i <= n; i++)
        cin >> Postorder[i];

    Preorder(1, n, 1, n);
}

/*
### 2263 - 트리의 순회

- 이해하는데 오래 걸림
- 루트 노드만 꺼내오는 형식
*/