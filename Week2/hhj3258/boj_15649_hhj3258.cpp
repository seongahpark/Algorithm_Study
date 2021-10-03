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
        // �ش� ��带 �湮���� �ʾҴٸ�
        if (!visited[i])
        {
            // �ش� ��� �湮 ó��
            visited[i] = true;
            // ��� �迭�� �ش� ���ڸ� �־���
            nums[cnt] = i + 1;
            // ��� �ݺ�(���� �ڽ� ��� �湮)
            Solve(nums, visited, cnt + 1);

            // ��Ϳ��� ���ƿ��� �̹湮 ó��
            // �� ó���� ���ϸ� i=0 ���� 0,1,2,3 �� �̹� ��� �湮 ó���Ǿ� �����Ƿ�
            // i=1������ �ƹ� ��嵵 �湮���� �ʴ´�.
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