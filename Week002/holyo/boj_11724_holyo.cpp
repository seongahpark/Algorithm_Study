#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int main() {
    int n, m;
    
    cin >> n >> m;
    
    vector<int> graph[n + 1];
    
    while (m--) {
        int u, v;
        
        cin >> u >> v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int cnt = 0;
    bool is_visited[n + 1];
    
    memset(is_visited, false, sizeof(is_visited));
    
    for (int ni = 1; ni <= n; ni++) {
        if (is_visited[ni]) continue;
        
        queue<int> q;
        
        q.push(ni);
        is_visited[ni] = true;
        cnt++;
        
        while (!q.empty()) {
            int curr =  q.front();
            
            q.pop();
            
            for (int si = 0; si < graph[curr].size(); si++) {
                int next = graph[curr][si];
                
                if (is_visited[next]) continue;
                
                q.push(next);
                is_visited[next] = true;
            }
        }
    }
    
    cout << cnt << '\n';
    
    return 0;
}
