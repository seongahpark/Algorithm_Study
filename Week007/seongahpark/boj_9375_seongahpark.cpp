#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {

        int n;
        cin >> n;
        int ans = 1;

        if (n == 0) ans = 0;
        else {
            unordered_map<string, int> umap;

            for (int j = 0; j < n; j++) {
                string name, type;
                cin >> name >> type;
                if (umap.find(type) != umap.end()) {          
                    int cnt = umap[type];
                    umap[type] = ++cnt;                     
                }
                else {
                    umap[type] = 1;        
                }
            }

            unordered_map<string, int>::iterator it;
            for (it = umap.begin(); it != umap.end(); it++) {
                ans *= ++(it->second);
            }
            ans -= 1;
        }
        cout << ans << "\n";
    }
    return 0;
}