#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;
    while (N--)
    {
        string inst, str;
        int num;
        deque<int> dq;

        bool err = false;
        bool rev = false;

        cin >> inst >> num >> str;

        int i = 1;

        while (str[i] != '\0')
        {
            int temp = 0;
            while (str[i] >= '0' && str[i] <= '9')
            {
                temp *= 10;
                temp += (int)(str[i] - '0');
                i++;
            }
            if (temp != 0)
            {
                dq.push_back(temp);
            }
            i++;
        }

        i = 0;
        while (inst[i] != '\0')
        {
            if (inst[i] == 'D')
            {
                if (dq.empty())
                {
                    cout << "error\n";
                    err = true;
                    break;
                }
                else
                {
                    if (rev)
                    {
                        dq.pop_back();
                    }
                    else
                    {
                        dq.pop_front();
                    }
                }
            }
            else if (inst[i] == 'R')
            {
                rev = !rev;
            }
            else
            {
                ;
            }
            i++;
        }

        if (err)
            continue;

        cout << "[";
        while (!dq.empty())
        {
            if (rev)
            {
                cout << dq.back();
                dq.pop_back();
            }
            else
            {
                cout << dq.front();
                dq.pop_front();
            }

            if (!dq.empty())
            {
                cout << ",";
            }
        }

        cout << "]\n";
    }

    return 0;
}