#include <bits/stdc++.h>
using namespace std;

string TagProcess(string str, int &idx)
{
    string ret = "";

    while (str[idx] != '>')
    {
        ret += str[idx++];
    }
    ret += str[idx++];

    return ret;
}

string ReverseStr(string str, int &idx)
{
    string ret;

    while (idx < str.size())
    {
        if (str[idx] == '<' || str[idx] == ' ')
            break;

        ret += str[idx++];
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

void Solve(string str)
{
    string answer = "";

    int idx = 0;
    while (idx < str.size())
    {
        if (str[idx] == ' ')
        {
            answer += ' ';
            idx++;
        }
        else if (str[idx] == '<')
        {
            answer += TagProcess(str, idx);
        }
        else
        {
            answer += ReverseStr(str, idx);
        }
    }

    cout << answer;
}

int main()
{
    string str;
    getline(cin, str);

    Solve(str);
}