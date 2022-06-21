#include <bits/stdc++.h>
using namespace std;

int S;

struct EmojiInfo
{
    int display = 0;
    int time = 0;
    int clipBoard = 0;
};

int Solve()
{
    vector<vector<bool>> visited(1001, vector<bool>(1001));

    queue<EmojiInfo> q;
    q.push({1, 0, 0});
    visited[1][0] = true;

    while (!q.empty())
    {
        int display = q.front().display;
        int time = q.front().time;
        int clipBoard = q.front().clipBoard;
        q.pop();

        if (display == S)
        {
            return time;
        }

        if (display > 0 && display < S)
        {
            // 삭제
            if (!visited[display - 1][clipBoard])
            {
                visited[display - 1][clipBoard] = true;
                q.push({display - 1, time + 1, clipBoard});
            }

            // 붙여넣기
            if (display + clipBoard < 1001 && clipBoard > 0)
            {
                if (!visited[display + clipBoard][clipBoard])
                {
                    visited[display + clipBoard][clipBoard] = true;
                    q.push({display + clipBoard, time + 1, clipBoard});
                }
            }

            // 복사
            if (!visited[display][display])
            {
                visited[display][display] = true;
                q.push({display, time + 1, display});
            }
        }
    }

    return -1;
}

int main()
{
    cin >> S;

    cout << Solve();
}