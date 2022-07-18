#include <iostream>

using namespace std;

int k, number;
int arr[1025]; // 입력
int answer[1025]; // 1을 루트노드로 한 노드 순서 배열
int cnt = 0;

void tree(int idx, int depth)
{
    if (depth == k) // 마치막 층
    {
        answer[idx] = arr[cnt++]; // 해당 노드만 값 넣어주고 끝
    }
    else
    {
        // 중위 순회
        tree(idx * 2, depth + 1); // 왼쪽 자식노드 검사
        answer[idx] = arr[cnt++]; // 현재 노드값 검사
        tree(idx * 2 + 1, depth + 1); // 오른쪽 자식노드 검사
    }
}

int main()
{
    cin >> k;
    number = (1 << k) - 1;
    for (int i = 0; i < number; i++) cin >> arr[i];

    tree(1, 1);

    for (int n = 0, idx = 1; n < k; n++)
    {
        for (int i = 0; i < 1 << n; i++)
        {
            cout << answer[idx++] << ' ';
        }
        cout << '\n';
    }
    return 0;
}