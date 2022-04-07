#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main(){
    int k, res = 0;
    cin >> k;
    while(k--){
        int num;
        cin >> num;
        if(num != 0){
            s.push(num);
            res += num;
        }else{
            res -= s.top();
            s.pop();
        }
    }
    cout << res;
    return 0;
}