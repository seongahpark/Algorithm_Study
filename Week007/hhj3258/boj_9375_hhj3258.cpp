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

        // 같은 종류의 옷은 한 번에 1개만 입거나 벗을 수 있음
        // 3_C_1 * 2_C_1 = 3 * 2
        // answer = (종류 1의 옷의 갯수 + 1) * (종류 2의 옷의 갯수 + 1) ... * (종류 n의 옷의 갯수 + 1)
        int answer = 1;
        for (auto it : my_map)
            answer *= (it.second + 1); // 안입는 경우의 수를 추가

        // 모든 옷을 안입는 경우 제거
        answer -= 1;

        cout << answer << '\n';
    }
}