#include <iostream>
#include <vector>
using namespace std;

#define max 101

int map[max][max];
bool visited[max];

int cnt = -1;

void dfs(int v, int n){
    visited[v] = true;
    cnt++;
    for(int i=0; i<=n; i++){
        if(map[v][i] == 1 && visited[i] == 0)
            dfs(i, n);
    }
}

int main(){
    int n, m, v = 1;
    int a, b;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    dfs(v, n);
    cout << cnt;

    return 0;
}
