#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
vector<int> v;
int main(){
    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++) q.push(i);

    int cnt = 0;
    while(!q.empty()){
        cnt++;
        int tmp = q.front();
        q.pop();
        if(cnt == k){
            v.push_back(tmp);
            cnt = 0;
        }else{
            q.push(tmp);
        }
    }
    cout << "<";
    for(int i=0; i<n; i++){
        if(i == n-1) cout << v[i] << ">";
        else cout << v[i] << ", ";
    }
    return 0;
}