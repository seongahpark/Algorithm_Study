#include <bits/stdc++.h>
using namespace std;

int T;
int K;

struct Info
{
    // 회전 방향
    int rotate_dir = 0;
    // 9시 방향 극, 3시 방향 극
    int left, right;
};

void Solve(vector<vector<int>> &gears, vector<pair<int, int>> &rules)
{
    // 회전 시킨 톱니바퀴(A)의 옆의 톱니바퀴(B)의 맞닿은 극이
    // 다르다면, B는 반대 방향으로 회전.
    // 같다면, B는 회전하지 않는다.
    // 연쇄적으로 반응이 일어날수도, 안일어날수도 있음.

    for (int k = 0; k < K; k++)
    {
        int gear_num = rules[k].first - 1;
        int dir = rules[k].second;

        vector<Info> gear_info(T);
        for (int t = 0; t < T; t++)
        {
            gear_info[t].left = gears[t][6];
            gear_info[t].right = gears[t][2];

            if (t == gear_num)
                gear_info[t].rotate_dir = dir;
        }

        // 회전 시킬 기어부터 --> 좌측으로
        for (int i = gear_num; i > 0; i--)
        {
            if (gear_info[i].rotate_dir == 0)
                break;

            if (gear_info[i].left != gear_info[i - 1].right)
                gear_info[i - 1].rotate_dir = gear_info[i].rotate_dir == 1 ? -1 : 1;
        }

        // 회전 시킬 기어부터 --> 우측으로
        for (int i = gear_num; i < T - 1; i++)
        {
            if (gear_info[i].rotate_dir == 0)
                break;

            if (gear_info[i].right != gear_info[i + 1].left)
                gear_info[i + 1].rotate_dir = gear_info[i].rotate_dir == 1 ? -1 : 1;
        }

        // rotate_dir 에 따라 기어들 회전
        for (int i = 0; i < T; i++)
        {
            // 반시계
            if (gear_info[i].rotate_dir == -1)
            {
                int temp = gears[i].front();
                gears[i].erase(gears[i].begin());
                gears[i].push_back(temp);
            }
            // 시계
            else if (gear_info[i].rotate_dir == 1)
            {
                vector<int> temp = gears[i];
                for (int j = 0; j < 7; j++)
                    gears[i][j + 1] = temp[j];
                gears[i][0] = temp[7];
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < T; i++)
        if (gears[i][0] == 1)
            answer++;

    cout << answer;
}

int main()
{
    cin >> T;

    vector<vector<int>> gears(T, vector<int>(8));
    string temp;
    // N극=0, S극=1
    for (int t = 0; t < T; t++)
    {
        cin >> temp;
        for (int j = 0; j < 8; j++)
            gears[t][j] = temp[j] - '0';
    }

    // 회전횟수
    cin >> K;

    vector<pair<int, int>> rules(K);
    for (int k = 0; k < K; k++)
    {
        // 회전시킨 톱니바퀴 번호 >> 회전 방향
        cin >> rules[k].first >> rules[k].second;
    }

    Solve(gears, rules);
}