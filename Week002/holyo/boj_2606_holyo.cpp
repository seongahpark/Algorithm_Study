#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int main() {
    int n, e;
    
    cin >> n >> e;
    
    vector<int> graph[n + 1];
    
    for (int ei = 0; ei < e; ei++) {
        int n1, n2;
        
        cin >> n1 >> n2;
        
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    
    int cnt = -1;
    bool is_visited[n + 1];
    
    memset(is_visited, false, sizeof(is_visited));
    
    queue<int> q;
    
    q.push(1);
    is_visited[1] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        
        q.pop();
        cnt++;
        
        for (int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];
            
            if (is_visited[next]) continue;
            
            q.push(next);
            is_visited[next] = true;
        }
    }
    
    cout << cnt << '\n';
    
    return 0;
}
