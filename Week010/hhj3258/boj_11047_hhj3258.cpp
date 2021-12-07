#include <iostream>
#include <vector>

using namespace std;

void Solve(int N, int K)
{
    vector<int> coins(N);

    for (int i = 0; i < N; i++)
        cin >> coins[i];

    int answer = 0;

    int coin = 0;
    int idx = N - 1;
    while (K > 0)
    {
        coin = coins[idx];

        if (coin > K)
        {
            idx--;
        }
        else if (coin <= K)
        {
            int temp = K / coin;
            K -= coin * temp;
            answer += temp;

            idx--;
        }
    }

    cout << answer;
}

int main()
{
    int N, K;
    // µ¿Àü Á¾·ù >> µ·
    cin >> N >> K;

    Solve(N, K);
}