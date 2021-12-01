#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(long long n1, long long n2)
    {
        if (abs(n1) > abs(n2))
            return true;
        else if (abs(n1) == abs(n2))
        {
            if (n1 > n2)
                return true;
            else
                return false;
        }

        return false;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    priority_queue<long long, vector<long long>, cmp> pq;

    int N;
    cin >> N;

    long long temp;

    while (N--)
    {
        cin >> temp;
        if (temp == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
            {
                cout << "0\n";
            }
        }
        else
        {
            pq.push(temp);
        }
    }

    return 0;
}