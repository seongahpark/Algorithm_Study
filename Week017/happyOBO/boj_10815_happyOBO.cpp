// 숫자 카드 10815
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <map>

using namespace std;
void solution(int N, int M, vector<int>& cards, vector<int>& numbers);
bool isInCards(int number, int N, vector<int>& cards);

int main()
{
    int N, M;
    
    cin >> N;
    vector<int> cards =  vector<int>(N);
    for (int i = 0; i < N; ++i)
        cin >> cards[i];

    cin >> M;
    vector<int> numbers = vector<int>(M);
    for (int i = 0; i < M; ++i)
        cin >> numbers[i];


    solution(N, M, cards, numbers);
}

void solution(int N, int M, vector<int>& cards, vector<int>& numbers)
{
    sort(cards.begin(), cards.end());
    for (auto number : numbers)
    {
        if (isInCards(number, N, cards)) cout << 1 << " ";
        else cout << 0 << " ";
    }
}

bool isInCards(int number, int N, vector<int>& cards)
{
    int minNumberIdx = 0;
    int maxNumberIdx = N - 1;
    int midNumberIdx = (minNumberIdx + maxNumberIdx) / 2;

    while (minNumberIdx < maxNumberIdx)
    {
        if (cards[midNumberIdx] == number)
            return true;
        else if (cards[midNumberIdx] < number)
            minNumberIdx = midNumberIdx + 1;
        else
            maxNumberIdx = midNumberIdx - 1;
        midNumberIdx = (minNumberIdx + maxNumberIdx) / 2;
    }
    if (cards[midNumberIdx] == number)
        return true;
    else
        return false;
}