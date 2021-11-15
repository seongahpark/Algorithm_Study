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

    // ũ�Ⱑ ���� ������ ū ������ �ڽ��� �ȴ�
    if (sizes[a] < sizes[b])
    {
        parent[a] = b;        // a�� �θ� = b
        sizes[b] += sizes[a]; // �θ� ũ�� += �ڽ� ũ��
        sizes[a] = 0;         // �ڽ� ũ�� = 0
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
            parent[i] = i; // ������ ����� �ʱ�ȭ
            sizes[i] = 1;  // ũ�� 1�� �ʱ�ȭ
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

            // ������ ��Ʈ(�ֻ��� �θ�)�� ���Ѵ�
            int name1Parent = GetParent(network[name1]);
            int name2Parent = GetParent(network[name2]);

            // �θ� ���� �ٸ��ٸ� �ϳ��� �������� ��ģ��
            if (name1Parent != name2Parent)
                Unite(name1Parent, name2Parent);

            // ��� �������� ���������� �𸣴� ���� ���ؼ� max�� ���
            cout << max(sizes[name1Parent], sizes[name2Parent]) << '\n';
        }
    }
}