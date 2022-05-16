#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 102;
bool visited[MAXSIZE] = {};

bool dfs(int N, vector<pair<int, int>>& graph, int start);
int getDist(pair<int, int>& from, pair<int, int>& to);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        vector<pair<int, int>> graph(N + 2);
        for (int i = 0; i < N + 2; i++)
        {
            cin >> graph[i].first >> graph[i].second;
        }

        if (dfs(N + 2, graph, 0))
        {
            cout << "happy" << "\n";
        }
        else
            cout << "sad" << "\n";

        fill(&visited[0], &visited[MAXSIZE], false);

    }

    

    return 0;
}


bool dfs(int N, vector<pair<int,int>>& graph, int start)
{
    stack<int> s;
    s.push(start);
    visited[start] = true;

    int curr, next;
    while (!s.empty())
    {
        curr = s.top();
        s.pop();

        if (getDist(graph[curr], graph[N - 1]) <= 1000)
            return true;

        for (int i = 1; i < N - 1; i++)
        {
            if (visited[i]) continue;
            if (getDist(graph[curr], graph[i]) <= 1000)
            {
                s.push(i);
                visited[i] = true;
            }
        }
    }

    return false;
}



int getDist(pair<int, int>& from, pair<int, int>& to)
{
    int dist = abs(from.first - to.first) + abs(from.second - to.second);

    return dist;
}