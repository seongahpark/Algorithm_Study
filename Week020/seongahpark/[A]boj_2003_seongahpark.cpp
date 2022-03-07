#include <iostream>
using namespace std;

int arr[10001];
int n, m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int left = 0, right = 0, sum = 0, cnt = 0;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    while(1){
        if(sum >= m) sum -= arr[left++]; 
        else if (right == n) break;
        else sum += arr[right++];

        if(sum == m) cnt++;
    }

    cout << cnt;
    return 0;
}