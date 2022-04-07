#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int N;
    cin>>N;
    stack<int> s;
    for(int i = 0; i<N; i++)
    {
        int e;
        cin>>e;
        if(e == 0)
        {
            s.pop();
        }
        else
        {
            s.push(e);
        }    
    }
    int count = 0;
    while(!s.empty())
    {
        count += s.top();
        s.pop();
    }

    cout<<count;
}