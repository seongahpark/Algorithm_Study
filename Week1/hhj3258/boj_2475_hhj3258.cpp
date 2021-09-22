#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> num(5);

    for (int i = 0; i < 5; i++)
        cin >> num[i];

    int answer = 0;

    for (int i = 0; i < num.size(); i++)
    {
        answer += num[i] * num[i];
    }

    answer = answer % 10;

    cout << answer;
}