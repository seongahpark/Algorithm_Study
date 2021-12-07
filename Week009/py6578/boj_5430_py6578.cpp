#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    priority_queue<unsigned int> pq;

    int N;
    cin >> N;
    unsigned int temp;
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