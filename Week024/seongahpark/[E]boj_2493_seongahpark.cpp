#include <iostream>
#include <stack>

using namespace std;
int arr[500001];

int main(){
    stack<pair<int, int> > s;
    int n;
    cin >> n;
    for(int i=0; i<n; i++ ){
        int tmp;
        cin >> tmp;
        while(!s.empty()){
            int front = s.top().first;
            if(front > tmp){
                arr[i] = s.top().second + 1;
                break;
            }else{
                s.pop();
            }
        }
        s.push(make_pair(tmp, i));
    }

    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}