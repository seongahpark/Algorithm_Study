#include <iostream>
#include <vector>

using namespace std;

int n, m;

void make_perm(vector<int> perm, vector<bool> is_visited) {
    if (perm.size() == m) {
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i] << ' ';
        }
        
        cout << '\n';
        
        return;
    }
    
    for (int ni = 1; ni <= n; ni++) {
        if (is_visited[ni]) continue;
        
        perm.push_back(ni);
        is_visited[ni] = true;
        
        make_perm(perm, is_visited);
        
        perm.pop_back();
    }
}

int main() {
    cin >> n >> m;
    
    vector<int> perm;
    vector<bool> is_visited(n + 1, false);
    
    make_perm(perm, is_visited);
    
    return 0;
}
