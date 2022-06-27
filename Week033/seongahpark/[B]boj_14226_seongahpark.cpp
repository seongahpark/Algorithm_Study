#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int visited[1001][1001];

int main(){
    int s;
    cin >> s;

    memset(visited, -1, sizeof(visited));
    queue<pair<int, int> > q;
    q.push({1, 0}); // 화면, 클립보드
    visited[1][0] = 0;
    
    while(!q.empty()){
        int dis = q.front().first;
        int clip = q.front().second;
        q.pop();

        if(dis == s){
            cout << visited[dis][clip];
            break;
        }

        // 화면에 있는 이모티콘 모두 copy 후 클립보드 저장
        if(visited[dis][dis] == -1){
            q.push({dis, dis});
            visited[dis][dis] = visited[dis][clip] + 1;
        }

        // 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
        if(dis + clip < 1001 && visited[dis + clip][clip] == -1){
            q.push({dis + clip, clip});
            visited[dis + clip][clip] = visited[dis][clip] + 1;
        }

        // 화면에 있는 이모티콘 중 하나 삭제
        if(dis > 0 && visited[dis - 1][clip] == -1){
            q.push({dis - 1, clip});
            visited[dis - 1][clip] = visited[dis][clip] + 1;
        }
    }

    return 0;
}