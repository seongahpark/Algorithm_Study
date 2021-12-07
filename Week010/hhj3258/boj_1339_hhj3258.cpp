#include <bits/stdc++.h>

using namespace std;

struct T
{
    int digit = 0;
    int num = 0;
};

bool cmp(pair<char, T> a, pair<char, T> b)
{
    return a.second.digit > b.second.digit;
}

int Solve(int &N, vector<string> &verb, unordered_map<char, T> &my_map)
{
    // map 의 내용을 벡터에 옮겨담고 자릿수(digit)의 내림차순으로 정렬해준다.
    vector<pair<char, T>> vec(my_map.begin(), my_map.end());
    sort(vec.begin(), vec.end(), cmp);

    // 가장 우선순위가 높은 알파벳의 숫자 = 9
    int max = 9;
    // vec는 자릿수의 내림차순 정렬이므로
    // 해당 vec를 인덱스로 해서 map을 돌며 숫자를 넣어준다.
    for (int i = 0; i < vec.size(); i++)
        my_map[vec[i].first].num = max--;

    int sum = 0;
    // 단어 갯수만큼 반복
    for (int i = 0; i < N; i++)
    {
        // 현재 단어의 길이만큼 반복
        for (int j = 0; j < verb[i].size(); j++)
        {
            // my_map[verb[i][j]].num = 숫자
            // digit = 해당 숫자의 자릿수
            double digit = pow(10, verb[i].size() - j - 1);
            sum += my_map[verb[i][j]].num * digit;
        }
    }

    return sum;
}

int main()
{
    int N;
    cin >> N;

    vector<string> verb(N);        // 인풋으로 들어올 단어들을 담아줄 벡터
    unordered_map<char, T> my_map; // key = 알파벳, value = 자릿수, 숫자
    for (int i = 0; i < N; i++)
    {
        cin >> verb[i];
        for (int j = 0; j < verb[i].size(); j++)
        {
            // 현재 단어의 자릿수를 계산한 후 map의 자릿수를 누적시켜준다. => 우선순위를 매긴다.
            double digit = pow(10, (verb[i].size() - j - 1));
            my_map[verb[i][j]].digit += digit;
        }
    }

    int answer = Solve(N, verb, my_map);
    cout << answer;
}