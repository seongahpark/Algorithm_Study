#include <bits/stdc++.h>

using namespace std;

struct Rect;
void solution(pair<int, int>& professor, pair<int, int>& seonggyu, vector<pair<int, int>>& students);
bool InArea(Rect& rect, pair<int, int> pos);
int getDistSquared(pair<int, int> p1, pair<int, int> p2);

const int MAXDISTSQUARED = 25;

struct Rect
{

    Rect(pair<int, int> p1, pair<int, int> p2)
    {
        leftUp = { min(p1.first,p2.first), min(p1.second, p2.second) };
        rightBottom = { max(p1.first,p2.first), max(p1.second, p2.second) };
    }
    pair<int, int> leftUp;
    pair<int, int> rightBottom;
};


int main() {

    int N;
    cin >> N;

    pair<int, int> professor, seonggyu;
    vector<pair<int, int>> students;

    int state;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> state;
            switch (state)
            {
            case 0:
                break;
            case 1:
                students.push_back({ i,j });
                break;
            case 2:
                seonggyu = { i,j };
                break;
            case 5:
                professor = { i, j };
                break;
            default:
                break;
            }
        }
    }


    solution(professor, seonggyu, students);

    return 0;
}

void solution(pair<int,int>& professor, pair<int,int>& seonggyu, vector<pair<int, int>>& students)
{
    Rect rect = Rect(professor, seonggyu);
    int counter = 0;

    if (getDistSquared(professor, seonggyu) < MAXDISTSQUARED)
        cout << 0;
    else
    {
        for (auto& student : students)
        {
            if (InArea(rect, student))
            {
                counter++;
            }
        }
        if (counter < 3)
            cout << 0;
        else
            cout << 1;
    }

}

bool InArea(Rect& rect, pair<int, int> pos)
{
    return  pos.first <= rect.rightBottom.first  &&  pos.second  <= rect.rightBottom.second &&
           rect.leftUp.first <= pos.first && rect.leftUp.second <= pos.second;
}

int getDistSquared(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}