#include <bits/stdc++.h>

using namespace std;


void solution(const int* ptr, int N, int M);

const int MAXSIZE = 10000;

int main() {

    int arr[MAXSIZE];
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    solution(arr, N, M);
    return 0;
}


void solution(const int* ptr, int N, int M)
{
    int currSum;
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        currSum = 0;
        for (int j = i; i < N; j++)
        {
            currSum += *(ptr + j);
            if (currSum == M)
            {
                counter++;
                break;
            }
            else if (M < currSum) break;
        }
    }

    cout << counter;
}
