#include <bits/stdc++.h>
using namespace std;

void Solve(vector<int> &rhythm)
{
    bool isAsc = true;
    bool isDesc = true;
    bool isMix = false;

    for (int i = 0; i < rhythm.size() - 1; i++)
    {
        if (isAsc)
        {
            if (rhythm[i] > rhythm[i + 1])
                isAsc = false;
        }

        if (isDesc)
        {
            if (rhythm[i] < rhythm[i + 1])
                isDesc = false;
        }

        if (!isAsc && !isDesc)
        {
            isMix = true;
            break;
        }
    }

    if (isAsc)
        cout << "ascending";
    else if (isDesc)
        cout << "descending";
    else
        cout << "mixed";
}

int main()
{
    vector<int> rhythm(8);

    for (int i = 0; i < rhythm.size(); i++)
        cin >> rhythm[i];

    Solve(rhythm);
}