#include <bits/stdc++.h>
using namespace std;

int N, M;

void Solve(vector<int> &nums, vector<bool> &visited, int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << nums[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        // 해당 노드를 방문하지 않았다면
        if (!visited[i])
        {
            // 해당 노드 방문 처리
            visited[i] = true;
            // 출력 배열에 해당 숫자를 넣어줌
            nums[cnt] = i + 1;
            // 재귀 반복(다음 자식 노드 방문)
            Solve(nums, visited, cnt + 1);

            // 재귀에서 돌아오면 미방문 처리
            // 이 처리를 안하면 i=0 에서 0,1,2,3 이 이미 모두 방문 처리되어 있으므로
            // i=1에서는 아무 노드도 방문하지 않는다.
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    vector<int> nums(M);
    vector<bool> visited(N);
    Solve(nums, visited, 0);
}