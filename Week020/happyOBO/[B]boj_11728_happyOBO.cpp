#include <bits/stdc++.h>

using namespace std;

void solution(vector<int>& v1, vector<int>& v2);

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<int> v1(N), v2(M);
	for (int i = 0; i < N; i++)
		cin >> v1[i];
	for (int i = 0; i < M; i++)
		cin >> v2[i];
	solution(v1, v2);
}


void solution(vector<int>& v1, vector<int>& v2)
{
	auto it1 = v1.begin(), it2 = v2.begin();
	while(it1 != v1.end() && it2 != v2.end())
	{
		if (*it1 < *it2)
			cout << *it1++ << " ";
		else
			cout << *it2++ << " ";
	}

	while (it1 != v1.end()) cout << *it1++ << " ";

	while (it2 != v2.end()) cout << *it2++ << " ";
}
