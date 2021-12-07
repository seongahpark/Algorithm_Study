#include <bits/stdc++.h>
using namespace std;

int parent[200000];
int sizes[200000];

int GetParent(int a)
{
    if (parent[a] == a)
        return a;

    return parent[a] = GetParent(parent[a]);
}

void Unite(int a, int b)
{
    a = GetParent(a);
    b = GetParent(b);

    // 크기가 작은 집합이 큰 집합의 자식이 된다
    if (sizes[a] < sizes[b])
    {
        parent[a] = b;        // a의 부모 = b
        sizes[b] += sizes[a]; // 부모 크기 += 자식 크기
        sizes[a] = 0;         // 자식 크기 = 0
    }
    else
    {
        parent[b] = a;
        sizes[a] += sizes[b];
        sizes[b] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int F; // F <= 100,000
    cin >> F;

    int input_num;
    string name1, name2;
    for (int f = 0; f < F; f++)
    {
        cin >> input_num;

        for (int i = 0; i < 200000; i++)
        {
            parent[i] = i; // 독립된 노드들로 초기화
            sizes[i] = 1;  // 크기 1로 초기화
        }
        unordered_map<string, int> network;
        int cnt = 1;
        for (int i = 0; i < input_num; i++)
        {
            cin >> name1 >> name2;

            if (network[name1] == 0)
                network[name1] = cnt++;
            if (network[name2] == 0)
                network[name2] = cnt++;

            // 각각의 루트(최상위 부모)를 구한다
            int name1Parent = GetParent(network[name1]);
            int name2Parent = GetParent(network[name2]);

            // 부모가 서로 다르다면 하나의 집합으로 합친다
            if (name1Parent != name2Parent)
                Unite(name1Parent, name2Parent);

            // 어느 집합으로 합쳐졌는지 모르니 둘이 비교해서 max값 출력
            cout << max(sizes[name1Parent], sizes[name2Parent]) << '\n';
        }
    }
}