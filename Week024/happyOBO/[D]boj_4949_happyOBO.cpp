#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    char c;
    
    bool check = true;
    while(true)
    {
        stack<char> s;
        c = (char) getchar();
        if(c == '.') break;

        while( c != '\n')
        {
            if(check)
            {

                if( c == '(' )
                {
                    s.push('(');
                }
                else if( c == '[')
                {
                    s.push('[');
                }
                else if(c == ')')
                {
                    if(!s.empty() && s.top() == '(') s.pop();
                    else check = false;
                }
                else if(c == ']')
                {
                    if( !s.empty() && s.top() == '[') s.pop();
                    else check = false;
                }
                else
                {
                    
                }
            }
            c = (char) getchar();
        }
        if(check && s.empty()) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
        check = true;
        
    }
}