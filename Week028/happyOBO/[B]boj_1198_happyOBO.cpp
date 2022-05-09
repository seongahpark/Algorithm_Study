#include <bits/stdc++.h>

using namespace std;

void solution(vector<pair<int, int>>& points);
int getArea(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> points;

    pair<int, int> p;
    for (int i = 0; i < N; i++)
    {
        cin >> p.first >> p.second;
        points.push_back(p);
    }
    solution(points);


    return 0;
}


void solution(vector<pair<int, int>>& points)
{

    int result = 0.0;

    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i+1; j < points.size(); j++)
        {
            for (int k = j + 1; k < points.size(); k++)
            {
                result = max(result, getArea(points[i], points[j], points[k]));
            }
        }
    }

    if (result % 2 == 1)
        cout << result / 2 << ".5";
    else
        cout << result / 2 << ".0";
}

 
int getArea(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3)
{
    return abs(((p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) - 
        (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second)));
}

