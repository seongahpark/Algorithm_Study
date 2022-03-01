#include <iostream>

using namespace std;

int arr[5][5], res = 0;
bool visited[1000001];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

//모든 정점에서 구할 수 있는 모든 숫자를 다 구해보면 되는 문제
//depth가 5가 되면 계산을 하도록 함
//더할 때, *10하는게 핵심
void dfs(int x, int y, int sum, int cnt){
    if(cnt == 5){
        if(visited[sum] == false){
            visited[sum] = true;
            res++;
        }
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5) dfs(nx, ny, sum*10+arr[nx][ny],cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            dfs(i, j, arr[i][j], 0);
        }
    }

    cout << res;
    return 0;
}
