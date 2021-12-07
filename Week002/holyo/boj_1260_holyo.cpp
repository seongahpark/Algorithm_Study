#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int MAX_N = 1'001;

bool is_visited[MAX_N];
vector<int> graph[MAX_N];

void dfs(int v) {
    is_visited[v] = true;
    
    cout << v << ' ';
    
    for (int i = 0; i < graph[v].size(); i++) {
        int next = graph[v][i];
        
        if (is_visited[next]) continue;
            
        dfs(next);
    }
}

void bfs(int v) {
    queue<int> q;
    
    q.push(v);
    is_visited[v] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        
        q.pop();
        cout << curr << ' ';
        
        for (int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];
            
            if (is_visited[next]) continue;
            
            q.push(next);
            is_visited[next] = true;
        }
    }
}

int main() {
    int n, m, v;
    
    cin >> n >> m >> v;
    
    for (int i = 0; i < m; i++) {
        int n1, n2;
        
        cin >> n1 >> n2;
        
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    dfs(v);
    
    cout << '\n';
    memset(is_visited, false, sizeof(is_visited));
    
    bfs(v);
    
    cout << '\n';
    
    return 0;
}
