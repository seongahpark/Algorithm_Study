#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 500001;
int n, m;
int arr[MAX];

int lower(int num){
    int left = 0, right = n-1, mid;
    while(1){
        mid = (left+right)/2;
        if(left > right){
            if(arr[left] == num) return left;
            else return -1;
        }
        if(arr[mid] >= num) right = mid-1;
        else left = mid+1;
    }
}

int upper(int num){
    int left = 0, right = n-1, mid;
    while(1){
        mid = (left+right)/2;
        if(left>right){
            if(arr[right] == num) return right;
            else return -1;
        }
        if(arr[mid] <= num) left = mid+1;
        else right = mid-1;
    }
}

//lower, upper bound 사용 문제
//몇 개의 카드를 갖고있는가? : upper bound - lowerbound + 1
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    cin >> m;
    int num, res;

    for(int i=0; i<m; i++){
        cin >> num;
        res = upper(num);
        if(res == -1) cout << "0 ";
        else cout << res - lower(num) + 1 << " ";
    }
    return 0;
}