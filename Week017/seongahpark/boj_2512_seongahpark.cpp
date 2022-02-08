#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int n, m, sum = 0, res;
int arr[MAX];

void BinarySearch(){
    //끝 값을 예산 요청에서 가장 큰 값으로 설정해야 함
    //중간값 보다 작으면 sum에 더하고 총액과 비교
    int left = 0, right = arr[n-1], mid;
    while(left<=right){
        sum = 0;
        mid = (left+right)/2;
        for(int i=0; i<n; i++){
            sum += min(arr[i], mid);
        }
        if(m >= sum){
            res = mid;
            left = mid+1;
        }
        else right = mid-1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    cin >> m;
    BinarySearch();
    cout << res;
    return 0;
}