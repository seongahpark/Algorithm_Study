#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


int getTopIdx(stack<pair<char,int>>& s);
void printOut(stack<pair<char,int>>& s);

int main() {
    // 1. 스택에 문자 형태로 추가하는데,
    // 2. 문자가 폭탄 단어의 어디까지 연속되었는지를 pair 형태로 추가한다.
    // 3. 연속 변수가 폭탄 단어 길이까지 늘어나면, 그때 연속 변수만큼 pop을 한다.
    // 4. 남은 문자들 순서대로 출력하기


    string S, bomb;

    cin >> S >> bomb;

    int bombLastIdx = bomb.size() -1;
    // first : 문자 , second : 폭탄 단어 동일 인덱스
    stack<pair<char,int>> s;
    int currIdx;
    for(auto c : S)
    {
        currIdx = getTopIdx(s);

        if(c == bomb[currIdx + 1])
            currIdx++;
        else if(c == bomb[0])
            currIdx = 0;
        else
            currIdx = -1;

        s.push({c , currIdx});

        if(currIdx == bombLastIdx)
        {
            while( 0 <= currIdx--)
                s.pop();
        }
    }

    printOut(s);

    return 0;
}


int getTopIdx(stack<pair<char,int>>& s)
{

    if(s.empty())
    {
        return -1;
    }
    else
    {
        return s.top().second;
    }
}

void printOut(stack<pair<char,int>>& s)
{
    stack<char> result;

    if(s.empty())
    {
        cout << "FRULA";
        return;
    }

    while(!s.empty())
    {
        result.push(s.top().first);
        s.pop();
    }

    while(!result.empty())
    {
        cout << result.top();
        result.pop();
    }
}