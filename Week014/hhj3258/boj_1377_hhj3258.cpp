#include <bits/stdc++.h>

using namespace std;

// 버블 정렬은 회전이 한 번 끝날 때마다
// 상대적으로 작은 숫자들이 1칸 씩만 앞으로 간다.
// 만약 3회전을 한다면 3칸 앞으로 이동한다.
// 퀵 소트로 정렬 후, max(기존 인덱스-현재 인덱스) 를 하면
// 버블정렬을 할 시 몇 회전을 통해 정렬을 완료했는지 알 수 있다.

void Solve(vector<pair<int, int>> &A, int N)
{
    sort(A.begin(), A.end());

    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        answer = max(answer, A[i].second - i + 1);
    }

    cout << answer;
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> A(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }

    Solve(A, N);
}