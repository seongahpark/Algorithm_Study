#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct info_ {
	string name;
	int korean;
	int english;
	int math;
}info;

vector<info> v;
int N;

bool compare(info A, info B)
{
	if (A.korean == B.korean)
	{
		if (A.english == B.english)
		{
			if (A.math == B.math)
			{
				return A.name < B.name;
			}
			else
			{
				return A.math > B.math;
			}
		}
		else
		{
			return A.english < B.english;
		}
	}
	else
	{
		return A.korean > B.korean;
	}
}

void solve(void)
{
	sort(v.begin(), v.end(), compare);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;

	info temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp.name >> temp.korean >> temp.english >> temp.math;
		v.push_back(temp);
	}

	solve();

	for (int i = 0; i < N; i++)
	{
		cout << v[i].name << "\n";
	}

	return 0;
}