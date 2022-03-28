#include <bits/stdc++.h>

using namespace std;


void solution(int R, vector<string>& columns);

int main() {
	int R, C;
	cin >> R >> C;
	vector<string> columns(C,"");

	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			char cc;
			cin >> cc;
			columns[c] += cc;
		}
	}
	solution(R, columns);

}


void solution(int R, vector<string>& columns)
{
	
	int counter = 0;
	for (int idx = 1; idx < R; idx++)
	{
		set<string> s;
		for (auto& c : columns)
		{
			string subColumn = c.substr(idx, c.size() - idx);
			if (s.find(c.substr(idx, c.size() - idx)) != s.end())
			{
				cout << counter;
				return;
			}
			else
				s.insert(subColumn);

		}
		counter++;
	}

	cout << counter;
}