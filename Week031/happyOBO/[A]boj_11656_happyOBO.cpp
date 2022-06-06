#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;

	set<string> ss;
	int len = s.size();
    
	for (int i = 0; i < len; i++)
		ss.insert(s.substr(i, len - i));

	for_each(ss.begin(), ss.end(), [](string s) { cout << s << "\n"; });

}

