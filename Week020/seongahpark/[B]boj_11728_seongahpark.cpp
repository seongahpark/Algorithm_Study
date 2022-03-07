#include <iostream>
#include <algorithm>
const int MAX = 1000001;
using namespace std;

int a[MAX], b[MAX], res[MAX*2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 

    int n, m;
    cin >> n >> m;

    for(int l=0; l<n; l++) cin >> a[l];
    for(int l=0; l<m; l++) cin >> b[l];

    int i=0, j=0, k=0; // a, b, res 배열의 각각의 인덱스
    while(i<n && j<m){
        if(a[i] < b[j]) res[k++] = a[i++];
        else res[k++] = b[j++];
    }
    while(i<n) res[k++] = a[i++];
    while(j<m) res[k++] = b[j++];

    for(int l=0; l<n+m; l++) cout << res[l] << " ";
    return 0;
}