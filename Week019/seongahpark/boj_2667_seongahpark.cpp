#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[26][26];
bool visited[26][26];
vector<int> v;

int n, cnt, res = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

//방문하지 않은 곳에서 dfs를 호출하는 문제
//호출하기 전에 cnt를 1로 초기화해주는 것이 중요!
//dfs가 끝나면 vector에 cnt값을 저장해주고, 단지 1개를 돌았다는 뜻으로 res++ 해줌
void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < n && ny < n){
            if(!visited[nx][ny] && arr[nx][ny]){
                visited[nx][ny] = true;
                cnt++;
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string str;

    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<str.length(); j++){
            visited[i][j] = false;
            if(str[j] == '1') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && !visited[i][j]){
                visited[i][j] = true;
                cnt = 1; //처음은 시작점 포함이니 1로 초기화
                dfs(i, j);
                v.push_back(cnt);
                res++;
            }
        }
    }

    sort(v.begin(), v.end());
    cout << res << "\n";

    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
    return 0;
}