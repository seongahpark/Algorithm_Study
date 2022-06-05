#include <bits/stdc++.h>
using namespace std;

vector<int> MakeTable(const string &target)
{
    vector<int> table(target.size());
    int j = 0;
    for (int i = 1; i < target.size(); i++)
    {
        while (j > 0 && target[i] != target[j])
        {
            j = table[j - 1];
        }

        if (target[i] == target[j])
        {
            table[i] = ++j;
        }
    }

    return table;
}

bool KMP(const string &str, const string &target)
{
    vector<int> table = MakeTable(target);

    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        while (j > 0 && str[i] != target[j])
        {
            j = table[j - 1];
        }

        if (str[i] == target[j])
        {
            if (j == target.size() - 1)
            {
                j = table[j];
                return true;
            }
            else
            {
                j++;
            }
        }
    }

    return false;
}

int main()
{
    string S;
    cin >> S;
    string P;
    cin >> P;

    if (KMP(S, P))
        cout << 1;
    else
        cout << 0;
}