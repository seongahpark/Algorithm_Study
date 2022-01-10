#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[5000000];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    // 수 N 개 >> K 번째 수
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    cout << arr[K - 1];
}