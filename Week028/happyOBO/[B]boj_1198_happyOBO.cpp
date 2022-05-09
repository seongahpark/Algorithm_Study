#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> sides(6);
    int countPerArea;
    map<int, vector<int>> idxFrequency = { {1,{}},{2,{}},{3,{}},{4,{}} };
    int s1, s2;
    s1 = s2 = -1;
    cin >> countPerArea;

    int arrow, side;
    for (int i = 0; i < 6; i++)
    {

        cin >> arrow >> side;
        idxFrequency[arrow].push_back(i);
        sides[i] = side;
    }
    for (int i = 0; i < 6; i++)
    {
        if (idxFrequency[i].size() == 1)
        {
            if (s1 == -1)
                s1 = idxFrequency[i][0];
            else
                s2 = idxFrequency[i][0];
        }
    }
    int area;
    if ( (s1 + 5) % 6 == s2)
    {
        area = sides[s1] * sides[s2] - (sides[(s1 + 2) % 6] * sides[(s2 + 4) % 6]);
    }
    else
    {
        area = sides[s1] * sides[s2] - (sides[(s2 + 2) % 6] * sides[(s1 + 4) % 6]);
    }
     
    cout << area * countPerArea;

    return 0;
}


