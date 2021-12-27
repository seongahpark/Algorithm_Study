#include <bits/stdc++.h>
using namespace std;

int N, M;

struct Coordinate
{
    int y, x;
};

int Dist_calc(Coordinate a, Coordinate b)
{
    return abs(a.y - b.y) + abs(a.x - b.x);
}

vector<vector<int>> BitMask_combi(int chicken_cnt)
{
    vector<vector<int>> combi;

    for (int i = 0; i < (1 << chicken_cnt); i++)
    {
        int cnt = 0;
        vector<int> indexs;
        for (int j = 0; j < chicken_cnt; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                cnt++;
                indexs.push_back(j);
            }
        }

        if (cnt == M)
        {
            combi.push_back(indexs);
        }
    }

    return combi;
}

void Solve(vector<Coordinate> &house, vector<Coordinate> &chicken)
{
    priority_queue<int, vector<int>, greater<int>> city_chicken_road;
    vector<vector<int>> combi = BitMask_combi(chicken.size());

    // 집마다의 치킨 로드를 구해야 함.
    // 치킨 로드 = 각 집에서 가장 가까운 치킨집까지 거리
    // 도시 치킨 로드 = 집마다의 치킨 로드 모두 더한 값

    // 조합 가짓수만큼 반복
    for (int i = 0; i < combi.size(); i++)
    {
        // 현재 조합의 도시 치킨 로드
        int now_city_chicken_road = 0;
        // 집 갯수만큼 반복
        for (int k = 0; k < house.size(); k++)
        {
            // 집마다의 치킨 로드
            int chicken_road = INT_MAX; // 초기화
            // 살아남은 치킨집(M)만큼 반복
            for (int j = 0; j < M; j++)
            {
                // 현재 집에서 가장 가까운 치킨집 업데이트
                chicken_road = min(chicken_road, Dist_calc(house[k], chicken[combi[i][j]]));
            }

            // 현재 조합의 도시 치킨 로드 += 현재 집의 치킨 로드
            now_city_chicken_road += chicken_road;
        }

        // 현재 조합의 도시 치킨 로드 push
        city_chicken_road.push(now_city_chicken_road);
    }

    // 모든 조합의 도시 치킨 로드 중 가장 작은 경우의 수 출력
    cout << city_chicken_road.top();
}

int main()
{
    // 도시의 크기 >> 살아남을 치킨집 갯수
    cin >> N >> M;

    vector<Coordinate> house;
    vector<Coordinate> chicken;
    int input = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input;

            if (input == 1)
                house.push_back({i, j});
            if (input == 2)
                chicken.push_back({i, j});
        }
    }

    Solve(house, chicken);
}