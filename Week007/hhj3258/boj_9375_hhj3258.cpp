#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int n;
        cin >> n;

        unordered_map<string, int> my_map;

        string category, tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp >> category;
            my_map[category]++;
        }

        // ���� ������ ���� �� ���� 1���� �԰ų� ���� �� ����
        // 3_C_1 * 2_C_1 = 3 * 2
        // answer = (���� 1�� ���� ���� + 1) * (���� 2�� ���� ���� + 1) ... * (���� n�� ���� ���� + 1)
        int answer = 1;
        for (auto it : my_map)
            answer *= (it.second + 1); // ���Դ� ����� ���� �߰�

        // ��� ���� ���Դ� ��� ����
        answer -= 1;

        cout << answer << '\n';
    }
}