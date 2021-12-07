#include <iostream>
#include <vector>

using namespace std;

int n, m;

void make_perm(vector<int> perm, vector<bool> is_visited) {
    int cnt = (int)perm.size();
    
    if (cnt == m) {
        for (int i = 0; i < cnt; i++) {
            cout << perm[i] << ' ';
        }
        
        cout << '\n';
        
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (is_visited[i]) continue;
        
        perm.push_back(i);
        is_visited[i] = true;
        
        make_perm(perm, is_visited);
        
        perm.pop_back();
        is_visited[i] = false;
    }
}

int main() {
    cin >> n >> m;
    
    vector<int> perm;
    vector<bool> is_visited(n + 1, false);
    
    make_perm(perm, is_visited);
    
    return 0;
}
