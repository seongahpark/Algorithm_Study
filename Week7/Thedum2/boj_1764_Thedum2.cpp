#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	set<string> Myset;
	vector<string> Myvector;

	int N, M;
	cin >> N >> M;

	string cmd;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		Myset.insert(cmd);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> cmd;
		if (Myset.find(cmd) != Myset.end())
			Myvector.push_back(cmd);
	}
	sort(Myvector.begin(), Myvector.end());
	cout << Myvector.size() << "\n";
	for (auto& n : Myvector)
		cout << n << "\n";

}