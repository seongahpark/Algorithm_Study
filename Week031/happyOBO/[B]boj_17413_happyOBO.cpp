#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void printWord(stack<char>& s);

int main() {
    // 1. ' ' 를 만나면 문자를 스택에 저장.
    // '<' 를 만나면 '>' 를 만날 때까지 스택에 넣지 말고 바로 출력


    bool tag_flag = false;
    stack<char> s;

    char c;

    while((c = getchar()) != '\n' && c != EOF)
    {
        if(c == '<') {
            printWord(s);
            tag_flag = true;
            cout << c;
        }
        else if( c == '>')
        {
            tag_flag = false;
            cout << c;
        }

        else if(tag_flag)
        {
            cout << c;
        }
        else if(!tag_flag)
        {
            if(c == ' ')
            {
                printWord(s);
                cout << c;
            }
            else
            {
                s.push(c);
            }
        }
    }

    printWord(s);

    return 0;
}

void printWord(stack<char>& s)
{
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}