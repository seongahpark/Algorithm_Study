#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    queue<int> q;
    for (int i = 1; i <= N; i++)
        q.push(i);

    while (q.size() != 1)
    {
        q.pop();              // �� �� ī�带 ������
        int temp = q.front(); // ���� ���� �� �� ī��
        q.pop();
        q.push(temp);
    }

    cout << q.front();
}