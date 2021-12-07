#include <iostream>
#include <vector>

using namespace std;

int n, m;

void make_perm(vector<int> perm) {
    if (perm.size() == m) {
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i] << ' ';
        }
        
        cout << '\n';
        
        return;
    }
    
    for (int ni = 1; ni <= n; ni++) {
        perm.push_back(ni);
        
        make_perm(perm);
        
        perm.pop_back();
    }
}

int main() {
    cin >> n >> m;
    
    vector<int> perm;
    
    make_perm(perm);
    
    return 0;
}
