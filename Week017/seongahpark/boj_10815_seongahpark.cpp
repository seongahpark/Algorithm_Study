#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 500001;
int a[MAX];
int b[MAX];
int ans[MAX] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++) cin >> b[i];

    sort(a, a+n);
    for(int i=0; i<m; i++){
        int left = 0;
        int right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(a[mid] == b[i]){
                ans[i] = 1;
                break;
            }

            if(a[mid] > b[i]){
                right = mid-1;
            }else left = mid+1;
        }
    }

    for(int i=0; i<m; i++) cout << ans[i] << " ";
    return 0;
}