#include <bits/stdc++.h>

using namespace std;

void solution(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3, pair<int, int>& p4);
bool isParallel(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3, pair<int, int>& p4);
bool isSame(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3, pair<int, int>& p4);


int main() {

    int N;
    cin >> N;
    pair<int, int> p1, p2, p3, p4;
    for (int i = 0; i < N; i++)
    {
        cin>> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;
        solution(p1,p2,p3,p4);
    }


    return 0;
}


void solution(pair<int,int>& p1, pair<int, int>& p2, pair<int, int>& p3, pair<int, int>& p4)
{
    if (isParallel(p1, p2, p3, p4))
    {
        if (isSame(p1, p2, p3, p4))
        {
            printf("LINE\n");
        }
        else
        {
            printf("NONE\n");
        }
    }
    else
    {
        float numeratorX = (p1.first * p2.second - p1.second * p2.first) * (p3.first - p4.first) - (p1.first - p2.first) * (p3.first * p4.second - p3.second * p4.first);
        float denominatorX = (p1.first - p2.first) * (p3.second - p4.second) - (p1.second - p2.second) * (p3.first - p4.first);

        float numeratorY = (p1.first * p2.second - p1.second * p2.first) * (p3.second - p4.second) - (p1.second - p2.second) * (p3.first * p4.second - p3.second * p4.first);
        float denominatorY = (p1.first - p2.first) * (p3.second - p4.second) - (p1.second - p2.second) * (p3.first - p4.first);

        printf("POINT %.2f %.2f\n", numeratorX / denominatorX, numeratorY / denominatorY);

    }
}

bool isParallel(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3, pair<int, int>& p4)
{
    return (p1.first - p2.first) * (p3.second - p4.second) - (p1.second - p2.second) * (p3.first - p4.first) == 0;
}

bool isSame(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3, pair<int, int>& p4)
{
    return (p1.first - p2.first) * (p3.second - p1.second) == (p1.second - p2.second) * (p3.first - p1.first);
}
