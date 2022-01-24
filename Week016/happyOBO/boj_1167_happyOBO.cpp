#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <limits.h>
#include <map>

using namespace std;
void solution(int N, vector<vector<pair<int, int>>>& graph);
void Init(int N);
void dfs(int start, vector<vector<pair<int, int>>>& graph);

int dist[100001];
int maxDistIdx = -1;
int maxDist = INT_MIN;

int main()
{
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> graph = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < N; ++i)
    {
        int from;
        cin >> from;
        while (true)
        {

            int to, w;
            cin >> to;
            if (to == -1)
                break;
            else
            {
                cin >> w;
                graph[from].push_back({ to, w });
            }
        }
    }



    solution(N, graph);
}
void solution(int N, vector<vector<pair<int, int>>>& graph)
{
    // 가장 먼 노드에서부터 먼노드 구하기
    int start = 1;
    Init(N);
    dfs(start, graph);
    start = maxDistIdx;
    Init(N);
    dfs(start, graph);

    cout << maxDist << endl;
}

void Init(int N)
{
    fill_n(dist, N + 1, INT_MIN);
    maxDistIdx = -1;
    maxDist = INT_MIN;
}

void dfs(int start, vector<vector<pair<int, int>>>& graph)
{
    stack<int> s;
    s.push(start);
    dist[start] = 0;
    maxDist = 0;
    while (!s.empty())
    {
        int currIdx = s.top();
        s.pop();

        for (pair<int, int> toWeight : graph[currIdx])
        {
            int to = toWeight.first;
            int weight = toWeight.second;
            if (dist[to] == INT_MIN)
            {
                dist[to] = dist[currIdx] + weight;
                s.push(to);
                if (dist[to] > maxDist)
                {
                    maxDist = dist[to];
                    maxDistIdx = to;
                }
            }
        }
    }

}