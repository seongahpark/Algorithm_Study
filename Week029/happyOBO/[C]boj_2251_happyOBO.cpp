#include <bits/stdc++.h>

using namespace std;


void bfs(vector<int>& capacities);


int main() {

    vector<int> capacities(3);

    cin >> capacities[0] >> capacities[1] >> capacities[2];
    bfs(capacities);

    return 0;
}


void bfs(vector<int>& capacities)
{
    set<pair<int, int>> visited;
    queue<pair<int,int>> q;
    visited.insert({ 0,0 });
    q.push({0,0});

    int c;
    vector<int> tmpBottles(3);
    while (!q.empty())
    {
        auto [a, b] = q.front(); q.pop();
        c = capacities[2] - a - b;

        vector<int> bottles = { a, b , c };
        
        for (int i = 0; i < 3; i++)
        {
            if (bottles[i] == 0) continue;

            {
                tmpBottles[(i + 1) % 3] = min(capacities[(i + 1) % 3], bottles[i] + bottles[(i + 1) % 3]);
                tmpBottles[(i + 2) % 3] = bottles[(i + 2) % 3];
                tmpBottles[i] = bottles[i] - (tmpBottles[(i + 1) % 3] - bottles[(i + 1) % 3]);

                if (visited.find({ tmpBottles[0], tmpBottles[1]}) == visited.end())
                {
                    q.push({ tmpBottles[0], tmpBottles[1] });
                    visited.insert({ tmpBottles[0], tmpBottles[1] });
                }
            }

            {
                tmpBottles[(i + 2) % 3] = min(capacities[(i + 2) % 3], bottles[i] + bottles[(i + 2) % 3]);
                tmpBottles[(i + 1) % 3] = bottles[(i + 1) % 3];
                tmpBottles[i] = bottles[i] - (tmpBottles[(i + 2) % 3] - bottles[(i + 2) % 3]);

                if (visited.find({ tmpBottles[0], tmpBottles[1] }) == visited.end())
                {
                    q.push({ tmpBottles[0], tmpBottles[1] });
                    visited.insert({ tmpBottles[0], tmpBottles[1] });
                }
            }
        }

    }

    set<int> results;

    for (auto& bt : visited)
    {
        auto& [a, b] = bt;
        if (a == 0)
            results.insert(capacities[2] - b);
    }

    for_each(results.begin(), results.end(), [](int x) { cout << x << " "; });

    return;

}