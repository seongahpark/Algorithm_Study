#include <bits/stdc++.h>
using namespace std;

string answer = "";

bool BoomChk(const string &boomStr)
{
    int answerIdx = answer.size() - 1;
    int boomStrIdx = boomStr.size() - 1;

    while (boomStrIdx >= 0)
    {
        // 한 문자라도 다르면 return false
        if (answer[answerIdx--] != boomStr[boomStrIdx--])
            return false;
    }

    return true;
}

// 스택처럼 가장 뒷 문자열을 pop
void RemoveBoom(int idx, int boomSize)
{
    for (int i = 0; i < boomSize; i++)
        answer.pop_back();
}

void Solve2(const string &str, const string &boomStr)
{
    int boomStrSize = boomStr.size();

    for (int i = 0; i < str.size(); i++)
    {
        answer += str[i];

        // 현재 문자가 boomStr 가장 뒷 문자와 같으면 boomStr인지 체크
        if (str[i] == boomStr[boomStrSize - 1])
            if (BoomChk(boomStr))
                RemoveBoom(i, boomStrSize);
    }

    if (answer.size() == 0)
        cout << "FRULA";
    else
        cout << answer;
}

int main()
{
    string str;
    cin >> str;
    string boomStr;
    cin >> boomStr;

    Solve2(str, boomStr);
}