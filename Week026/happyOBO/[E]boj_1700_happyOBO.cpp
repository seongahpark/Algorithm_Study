// 멀티탭 스케쥴링
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

void solution(int N, int K, vector<int>& order, unordered_map<int, priority_queue<int,vector<int>,greater<int>>>& frequency);

int main() {
    int N,K;
    cin >> N >> K;
    unordered_map<int, priority_queue<int,vector<int>,greater<int>>> frequency;
    vector<int> order(K);

    for(int i = 0; i < K; i++)
    {
        cin >> order[i];
        if(frequency.find(order[i]) == frequency.end())
            frequency[order[i]] = priority_queue<int,vector<int>, greater<int>>();
        frequency[order[i]].push(i);
    }
    solution( N, K, order, frequency);

    return 0;
}


void solution(int N, int K, vector<int>& order, unordered_map<int, priority_queue<int,vector<int>,greater<int>>>& frequency)
{
    // 처음에는 -1(empty) 로 초기화
    vector<int> multitap(N, -1);
    vector<bool> plugged(K + 1,false);

    int i, counter = 0, idx = 0;
    // 멀티탭 비워있는 만큼 채워 넣기 탐색
    // idx : 현재 탐색하는 전기용품, i : 현재 탐색하는 멀티탭 idx
    for(i = 0, idx = 0; idx < order.size() && i < N; idx++)
    {
        // 멀티탭에 존재하지 않는 전기 용품이라면 채워주지 않는다.
        if(!plugged[order[idx]])
        {
            multitap[i++] = order[idx];
            plugged[order[idx]] = true;
        }
        // 해당 전자기기 탐색했으니 팝해주기
        frequency[order[idx]].pop();

    }

    // 현재 멀티탭에 추가할 전기용품 , 멀티탭에 추가되어있는 전기용뭎, 변경될 전기 용품
    int currObj, existObj;
    int maxOrder, changeIdx;
    for( ; idx < order.size(); idx++)
    {
        currObj = order[idx];
        maxOrder = INT_MIN;

        if(plugged[currObj])
        {
            frequency[currObj].pop();
            continue;
        }

        for(int mIdx = 0; mIdx < multitap.size(); mIdx++)
        {
            existObj = multitap[mIdx];
            if(existObj == currObj) continue;
            // 1. 더이상 등장하지 않는 가전제품 먼저 교체
            if(frequency[existObj].empty())
            {
                changeIdx = mIdx;
                break;
            }
            else
            {
                // 가장 늦게 오는 전기 용품부터 교체
                if(maxOrder < frequency[existObj].top())
                {
                    maxOrder = frequency[existObj].top();
                    changeIdx = mIdx;
                }
            }

        }
        plugged[multitap[changeIdx]] = false;
        multitap[changeIdx] = currObj;
        plugged[currObj] = true;
        frequency[currObj].pop();
        counter++;
    }

    cout << counter;
}