// 2110 공유기 설치
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <map>

using namespace std;
void solution(int N, int C, vector<long long>& houses);
long long binarySearch(int N, int C, vector<long long>& houses);
bool canPlacedWithInDistance(int placeCount, long long distance, vector<long long>& houses);


int main()
{
    int N, C;

    cin >> N >> C;
    vector<long long> houses = vector<long long>(N);
    for (int i = 0; i < N; ++i)
        cin >> houses[i];
    
    sort(houses.begin(), houses.end());
    solution(N, C, houses);
}

void solution(int N , int C, vector<long long>& houses)
{
    cout << binarySearch(N, C, houses);
}

long long binarySearch(int N, int C, vector<long long>& houses)
{
    long long minDistance = 1;
    long long maxDistance = houses[N - 1] - houses[0];
    long long midDistance = (maxDistance + minDistance) / 2;
    long long result = LLONG_MIN;

    while (minDistance <= maxDistance)
    {
        if (canPlacedWithInDistance(C, midDistance, houses))
        {
            result = max(result, midDistance);
            minDistance = midDistance + 1;
        }
        else
            maxDistance = midDistance - 1;
        midDistance = (maxDistance + minDistance) / 2;
    }
    return result;
}

bool canPlacedWithInDistance(int placeCount, long long distance, vector<long long>& houses)
{
    long long recentPlacedPos = houses[0];
    placeCount--;
    for (auto& pos : houses)
    {
        if (placeCount <= 0)
            break;
        if (distance <= pos - recentPlacedPos)
        {
            recentPlacedPos = pos;
            placeCount--;
        }
    }

    if (placeCount <= 0)
        return true;
    else
        return false;

}