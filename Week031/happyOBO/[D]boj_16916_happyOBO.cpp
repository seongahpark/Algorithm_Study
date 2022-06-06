#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;


vector<int> getPi(string p);
void kmp(string s, string p);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S, substr;

    cin >> S >> substr;

    kmp(S, substr);

    return 0;
}


void kmp(string s, string p)
{
    auto pi = getPi(p);
    int n, m, j = 0;
    n = s.size();
    m = p.size();

    for (int i = 0; i < n; i++)
    {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j])
        {
            if (j == m - 1)
            {
                cout << 1;
                return;
            }
            else
                j++;
        }
    }

    cout << 0;
}

vector<int> getPi(string p)
{
    int m = p.size(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }

    return pi;
}

