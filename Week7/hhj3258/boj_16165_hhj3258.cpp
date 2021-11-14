#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    // 걸그룹 수 >> 문제 수
    cin >> N >> M;

    // map<그룹이름,멤버이름>
    unordered_map<string, vector<string>> groups;
    // map<멤버이름,그룹이름>
    unordered_map<string, string> members;

    // 걸그룹 수만큼 반복
    for (int n = 0; n < N; n++)
    {
        string girl_group;
        cin >> girl_group;

        int mem_size;
        cin >> mem_size;

        string member_name;
        groups[girl_group].resize(mem_size); // 벡터 크기 재할당(속도 향상)
        for (int i = 0; i < mem_size; i++)
        {
            cin >> member_name;

            groups[girl_group][i] = member_name;

            members[member_name] = girl_group;
        }
    }

    for (int m = 0; m < M; m++)
    {
        // 문제 : 걸그룹명 or 멤버명
        string q_str;
        cin >> q_str;

        // 문제 카테고리 : 0 or 1
        int q_category;
        cin >> q_category;

        // 카테고리 0 일 때 주어진 걸그룹의 멤버 사전순 출력
        if (q_category == 0)
        {
            sort(groups[q_str].begin(), groups[q_str].end());

            for (string member : groups[q_str])
                cout << member << '\n';
        }
        // 카테고리 1 일 때 주어진 멤버의 걸그룹명 출력
        else
        {
            cout << members[q_str] << '\n';
        }
    }
}