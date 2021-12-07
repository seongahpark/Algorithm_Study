#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    // �ɱ׷� �� >> ���� ��
    cin >> N >> M;

    // map<�׷��̸�,����̸�>
    unordered_map<string, vector<string>> groups;
    // map<����̸�,�׷��̸�>
    unordered_map<string, string> members;

    // �ɱ׷� ����ŭ �ݺ�
    for (int n = 0; n < N; n++)
    {
        string girl_group;
        cin >> girl_group;

        int mem_size;
        cin >> mem_size;

        string member_name;
        groups[girl_group].resize(mem_size); // ���� ũ�� ���Ҵ�(�ӵ� ���)
        for (int i = 0; i < mem_size; i++)
        {
            cin >> member_name;

            groups[girl_group][i] = member_name;

            members[member_name] = girl_group;
        }
    }

    for (int m = 0; m < M; m++)
    {
        // ���� : �ɱ׷�� or �����
        string q_str;
        cin >> q_str;

        // ���� ī�װ� : 0 or 1
        int q_category;
        cin >> q_category;

        // ī�װ� 0 �� �� �־��� �ɱ׷��� ��� ������ ���
        if (q_category == 0)
        {
            sort(groups[q_str].begin(), groups[q_str].end());

            for (string member : groups[q_str])
                cout << member << '\n';
        }
        // ī�װ� 1 �� �� �־��� ����� �ɱ׷�� ���
        else
        {
            cout << members[q_str] << '\n';
        }
    }
}