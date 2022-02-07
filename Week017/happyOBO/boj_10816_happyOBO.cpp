// 숫자 카드 2
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

int main()
{
    int N, M;

    cin >> N;
    vector<int> cards = vector<int>(N);
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
        cout << upper_bound(cards.begin(), cards.end(), number) - lower_bound(cards.begin(), cards.end(), number) << " ";
    }

}
