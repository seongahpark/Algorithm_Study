#include <bits/stdc++.h>

using namespace std;

void Solve(int &money, int coin, int &answer)
{
    int temp = money / coin;
    money -= coin * temp;
    answer += temp;
}

int main()
{
    int money;
    cin >> money;
    money = 1000 - money;

    int answer = 0;

    while (money > 0)
    {
        if (money >= 500)
            Solve(money, 500, answer);
        else if (money >= 100)
            Solve(money, 100, answer);
        else if (money >= 50)
            Solve(money, 50, answer);
        else if (money >= 10)
            Solve(money, 10, answer);
        else if (money >= 5)
            Solve(money, 5, answer);
        else if (money >= 1)
            Solve(money, 1, answer);
    }

    cout << answer;
}