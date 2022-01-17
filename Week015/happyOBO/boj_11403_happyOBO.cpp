#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>


using namespace std;

void solution(int N, vector<vector<int>>& graph);
void FloydWarshall(int N, vector<vector<int>>& graph);

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> graph = vector<vector<int>>(N + 1, vector<int>(N + 1));

    for (int from = 1; from <= N; from++)
        for (int to = 1; to <= N; to++)
            cin >> graph[from][to];


    solution(N, graph);
}

void solution(int N, vector<vector<int>>& graph)
{
    FloydWarshall(N, graph);
    for (int from = 1; from <= N; from++)
    {
        for (int to = 1; to <= N; to++)
        {
                cout << graph[from][to] << " ";
        }
        cout << endl;
    }

}


void FloydWarshall(int N, vector<vector<int>>& graph)
{
    for (int stopover = 1; stopover <= N; stopover++)
        for(int from = 1; from <= N; from++)
            for(int to = 1; to <= N; to++)
            {
                if (stopover == from || stopover == to)
                    continue;
                if (graph[from][to] == 1)
                    continue;
                // stopover 노드를 경유하면 from -> to 로 갈수 있는지 판단
                graph[from][to] = (graph[from][stopover] == 1 && graph[stopover][to] == 1)? 1 : 0;
            }
}