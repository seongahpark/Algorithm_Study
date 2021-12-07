#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    int temp;
    priority_queue<int> pq;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> temp;
            pq.push(-temp);

            if (pq.size() > N)
            {
                pq.pop();
            }
        }
    }

    cout << -pq.top() << "\n";

    return 0;
}