// 2512 예산
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
void solution(const int N, const vector<long long>& requests, long long totalBudget );
long long binarySearch(const int N, const vector<long long>& requests, long long totalBudget );
long long accRequest(long long stdRequest , const vector<long long>& requests);

int main()
{
    int N;
    long long totalBudget;
    cin >> N;
    vector<long long> requests(N);
    for(int i = 0; i < N; i++) cin >> requests[i];
    cin >> totalBudget;

    solution(N, requests, totalBudget );
    return 0;
}


void solution(const int N, const vector<long long>& requests, long long totalBudget )
{
    long long result;
    long long sumRequires = accumulate(requests.begin(), requests.end(), 0);
    if(totalBudget < sumRequires)
        result = binarySearch(N, requests, totalBudget );
    else
        result = *max_element(requests.begin(), requests.end());

    cout << result;
}



long long binarySearch(const int N, const vector<long long>& requests, long long totalBudget )
{
    long long minBudget = 0;
    long long maxBudget = totalBudget;
    long long midBudget = (minBudget + maxBudget) / 2;

    while(minBudget <= maxBudget)
    {
        long long reqBudget = accRequest( midBudget, requests);
        if(totalBudget == reqBudget) return midBudget;
        else if(totalBudget < reqBudget) maxBudget = midBudget -1;
        else minBudget = midBudget + 1;
        midBudget = (minBudget + maxBudget) / 2;
    }

    return midBudget;
}

long long accRequest(long long stdRequest , const vector<long long>& requests)
{
    long long result = 0;
    for(auto& req : requests)
    {
        if(stdRequest < req) result += stdRequest;
        else result += req;
    }

    return result;
}