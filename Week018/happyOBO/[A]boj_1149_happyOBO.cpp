#include <bits/stdc++.h>

using namespace std;

enum class Color;
void solution(int N, vector<map<Color, int>>& colorWeight);
int DP(int N, vector<map<Color, int>>& colorWeight);
enum class Color
{
    Red = 0,
    Green = 1,
    Blue = 2,
};

int main(void)
{
    int N;
    cin >> N;
    auto colorWeight = vector<map<Color, int>>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> colorWeight[i][Color::Red] >> colorWeight[i][Color::Green] >> colorWeight[i][Color::Blue];
    }

    solution(N, colorWeight);
}

void solution(int N, vector<map<Color, int>>& colorWeight) {
    int result = DP(N, colorWeight);
    cout << result;
}


int DP(int N, vector<map<Color, int>>& colorWeight)
{
    auto accMinWeight = vector<map<Color, int>>(N);
    accMinWeight[0][Color::Red] = colorWeight[0][Color::Red];
    accMinWeight[0][Color::Green] = colorWeight[0][Color::Green];
    accMinWeight[0][Color::Blue] = colorWeight[0][Color::Blue];

    for (int i = 1; i < N; ++i)
    {
        accMinWeight[i][Color::Red] = colorWeight[i][Color::Red] + 
                                        min(accMinWeight[i - 1][Color::Green],
                                            accMinWeight[i - 1][Color::Blue]);
        accMinWeight[i][Color::Green] = colorWeight[i][Color::Green] +
                                        min(accMinWeight[i - 1][Color::Red],
                                            accMinWeight[i - 1][Color::Blue]);
        accMinWeight[i][Color::Blue] = colorWeight[i][Color::Blue] +
                                        min(accMinWeight[i - 1][Color::Red],
                                            accMinWeight[i - 1][Color::Green]);
    }

    return min(accMinWeight[N - 1][Color::Red],
            min(accMinWeight[N - 1][Color::Green], 
                accMinWeight[N - 1][Color::Blue]));
}