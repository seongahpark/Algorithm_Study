#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct pos_
{
	int x;
	int y;
}pos;

vector<pos> v;
int N;

bool compare(pos A, pos B)
{
	if (A.y == B.y)
	{
		return A.x < B.x;
	}
	else
	{
		return A.y < B.y;
	}
}

void solve(void)
{
	sort(v.begin(), v.end(), compare);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	pos temp;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp.x >> temp.y;
		v.push_back(temp);
	}

	solve();

	for (int i = 0; i < N; i++)
	{
		cout << v[i].x << " " << v[i].y << "\n";
	}

	return 0;
}