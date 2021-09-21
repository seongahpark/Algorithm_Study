#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    cout << max(A, B);
}