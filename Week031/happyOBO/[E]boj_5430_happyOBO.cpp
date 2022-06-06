#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

void solution(string cmd, deque<int>& dq);
void print(bool is_reverse, deque<int>& dq);

int main() {

    int T, N;
    cin >> T;

    while (T--)
    {
        string cmd;
        cin >> cmd >> N;

        char c;
        int multiple = 10;
        int num = 0;
        deque<int> dq;
        getchar(); getchar();
        while ((c = getchar()) != ']')
        {
            if (c != ',')
            {
                num *= multiple;
                num += (c - '0');
            }
            else
            {
                dq.push_back(num);
                num = 0;
            }
        }

        if (dq.size() < N)
            dq.push_back(num);


        solution(cmd, dq);
    }


    

    return 0;
    
}

void solution(string cmd, deque<int>& dq)
{
    bool is_reverse = false;
    for (auto c : cmd)
    {
        if (c == 'R') is_reverse = !is_reverse;
        if (c == 'D')
        {
            if (dq.empty())
            {
                cout << "error" << "\n";
                return;
            }
            if (is_reverse) dq.pop_back();
            else dq.pop_front();
        }
    }

    print(is_reverse, dq);
}

void print(bool is_reverse, deque<int>& dq)
{
    cout << "[";
    if (is_reverse)
    {
        while (!dq.empty())
        {
            cout << dq.back();
            dq.pop_back();
            if (!dq.empty()) cout << ",";
        }
    }
    else
    {
        while (!dq.empty())
        {
            cout << dq.front();
            dq.pop_front();
            if (!dq.empty()) cout << ",";
        }
    }
    cout << "]" << "\n";
}
