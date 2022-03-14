#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void backtrk(int curridx, int vowelCount, string tmp);
void solution();

vector<char> alphabets;
vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
vector<string> results;
int L, C;

int main() {
    cin >> L >> C;
    alphabets.resize(C);
    for(int i = 0; i < C; i++)
        cin >> alphabets[i];
    sort(alphabets.begin(), alphabets.end());
    solution();
    return 0;
}


void solution()
{
    backtrk(0,0,"");
    for_each(results.begin(), results.end(), [](string s){cout << s << "\n";});
}

void backtrk(int curridx, int vowelCount, string tmp)
{
    if(tmp.size() == L)
    {
        if(0 < vowelCount && 2 <= L - vowelCount)
            results.push_back(tmp);
    }
    else
    {
        for(int i = curridx; i < C; i++)
        {
            char c = alphabets[i];

            if(find(vowels.begin(), vowels.end(), c) != vowels.end())
                backtrk(i + 1,vowelCount + 1, tmp+c);
            else
                backtrk(i + 1,vowelCount, tmp+c);
        }

    }
}