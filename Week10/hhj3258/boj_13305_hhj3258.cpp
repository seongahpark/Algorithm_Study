#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solve(int &N, vector<int> &lens, vector<int> &city)
{
    // 현재 도시의 기름 값
    long long oil_money = city[0];
    // 마지막 도시까지 도착하기 위한 총 금액 = 거리 * 기름 값
    long long total_money = lens[0] * oil_money;

    for (int i = 1; i < N - 1; i++)
    {
        // 포인트는 더 작은 값을 만날 때만 바꿔준다는 것
        // 만약 i 번째 도시의 기름 값이 더 싸다면
        if (oil_money > city[i])
            // i 번째 도시의 기름 값으로 oil_money를 바꾼다.
            oil_money = city[i];

        // 총 기름 값은 인덱스(거리)가 증가할 때마다 누적시켜준다.
        total_money += (lens[i] * oil_money);
    }

    cout << total_money;
}

int main()
{
    int N;
    cin >> N;

    vector<int> lens(N - 1);
    for (int i = 0; i < N - 1; i++)
        cin >> lens[i];

    vector<int> city(N);
    for (int i = 0; i < N; i++)
        cin >> city[i];

    Solve(N, lens, city);
}