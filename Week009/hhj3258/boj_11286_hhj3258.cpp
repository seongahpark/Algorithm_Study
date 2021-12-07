#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct comp
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        else
            return abs(a) > abs(b);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, comp> pq;

    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        if (input == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
                cout << "0\n";
        }
        else
            pq.emplace(input);
    }
}