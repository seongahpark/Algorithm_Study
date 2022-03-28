#include <bits/stdc++.h>

using namespace std;
void solution(string s);

int main() {

	string s;
	cin >> s;
	solution(s);
}

void solution(string s)
{
	set<string> ss;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 1; j <= s.size() - i; j++)
		{
			ss.insert(s.substr(i, j));
		}
	}

	cout << ss.size();
}