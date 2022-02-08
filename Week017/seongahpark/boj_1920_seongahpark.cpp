#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int n, m;
int arr[MAX];

void BinarySearch(int num){
    int left = 0, right = n-1, mid;
    while(left<=right){
        mid = (left+right)/2;
        if(arr[mid] == num){
            cout << 1 << "\n";
            return;
        }else if(arr[mid] > num) right = mid-1; //num이 배열 중앙값보다 작으면 왼쪽으로
        else left=mid+1;//크면 오른쪽으로 이동
    }

    cout << 0 << "\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    cin >> m;
    int tmp;
    for(int i=0; i<m; i++){
        cin >> tmp;
        BinarySearch(tmp);
    }
    return 0;
}