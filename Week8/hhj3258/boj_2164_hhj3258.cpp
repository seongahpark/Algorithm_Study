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
        q.pop();              // 맨 위 카드를 버린다
        int temp = q.front(); // 버린 뒤의 맨 위 카드
        q.pop();
        q.push(temp);
    }

    cout << q.front();
}