#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        stack<char> my_stack;

        string input;
        cin >> input;

        int cnt = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '(')
                cnt++;
            else
                cnt--;

            if (cnt < 0)
                break;
        }

        if (cnt == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}