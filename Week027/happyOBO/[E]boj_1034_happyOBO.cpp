// 램프
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void solution(int N, int M, int K, unordered_map<string,pair<int,int>>& freqRow);

int main() {
    int N, M, K;
    unordered_map<string, pair<int,int>> freqRow;
    cin >> N >> M;

    string r;
    for(int i = 0; i < N; i++)
    {
        cin >> r;
        if(freqRow.find(r) == freqRow.end())
            freqRow[r] = {count(r.begin(), r.end(), '0'), 1};
        else
            freqRow[r].second++;
    }

    cin >> K;

    solution(N,M,K,freqRow);

    return 0;
}

// 0의 개수가 k개 , k-2개,..., 0개 인 것 중에 빈도수가 가장 높은 것 탐색

void solution(int N, int M, int K, unordered_map<string,pair<int,int>>& freqRow)
{
    int result = 0;
    for(int k = K; 0 <= k; k-= 2)
    {
        for(auto& row : freqRow)
        {
            if(row.second.first == k)
                result = max(row.second.second, result);
        }
    }

    cout << result;
}
