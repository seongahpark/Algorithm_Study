#include <bits/stdc++.h>


using namespace std;

void solution(int N);
void dijkstra(int N, pair<int, int> start);
bool canGo(int N, pair<int, int> pos);


pair<int, int> Directions[4] = { {1, 0}, {-1, 0}, {0, 1} , {0, -1} };

const int MAXSIZE = 50;

char graph[MAXSIZE][MAXSIZE] = {};
int changeCount[MAXSIZE][MAXSIZE] = {};

int main()
{


    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> graph[i][j];

    fill(&changeCount[0][0], &changeCount[N -1][N], INT_MAX);
    solution(N);

}


void solution(int N)
{
    dijkstra(N, { 0,0 });
    cout << changeCount[N - 1][N - 1];
}


void dijkstra(int N, pair<int,int> start)
{
    // first : 검 -> 흰방으로 만든 개수 , second : index (pair) 
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
    pq.emplace(0, start);
    changeCount[start.first][start.second] = 0;

    while (!pq.empty())
    {
        auto curr = pq.top().second;
        int cnt = pq.top().first;
        pq.pop();

        if (changeCount[curr.first][curr.second] < cnt)
            continue;
        for (auto& dir : Directions)
        {
            pair<int, int> next = {curr.first + dir.first , curr.second + dir.second};
            if (!canGo(N, next))
                continue;

            if (graph[next.first][next.second] == '1')
            {
                if (changeCount[next.first][next.second] == INT_MAX || changeCount[curr.first][curr.second] < changeCount[next.first][next.second])
                {
                    changeCount[next.first][next.second] = changeCount[curr.first][curr.second];
                    pq.emplace(changeCount[next.first][next.second], next);
                }
            }
            else
            {
                if (changeCount[next.first][next.second] == INT_MAX || changeCount[curr.first][curr.second] + 1 < changeCount[next.first][next.second])
                {
                    changeCount[next.first][next.second] = changeCount[curr.first][curr.second] + 1;
                    pq.emplace(changeCount[next.first][next.second], next);
                }
            }

        }

    }

}


bool canGo(int N, pair<int, int> pos)
{
    if (pos.first < 0 || N <= pos.first)
        return false;
    if (pos.second < 0 || N <= pos.second)
        return false;
    return true;
}
