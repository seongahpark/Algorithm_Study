#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 1001

int map[MAX][MAX];
bool visited[MAX];
queue<int> q;
int n, m, v;

void reset(){
    for(int i=1; i<=n; i++){
        visited[i] = 0;
    }
}
void DFS(int v){
    visited[v] = true;
    cout << v << " ";

    for(int i=1; i<=n; i++){
        if(map[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

void BFS(int v){
    q.push(v);
    visited[v] = true;
    cout << v << " ";

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 1; i<= n; i++){
            if(map[v][i] == 1 && visited[i]==0){
                q.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }
}

int main(){

    cin >> n >> m >> v;
    
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    DFS(v);
    cout << endl;
    reset();
    BFS(v);

    return 0;
}
