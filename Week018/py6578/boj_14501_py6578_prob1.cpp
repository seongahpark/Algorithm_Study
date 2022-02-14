#include <iostream>
#include <algorithm>
using namespace std;

#define MAX	1001

int color[3];
int house[MAX][3];
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;

	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;

	for (int i = 1; i <= N; i++)
	{
		cin >> color[0] >> color[1] >> color[2];
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + color[0];
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + color[1];
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + color[2];
	}

	cout << min(house[N][0], min(house[N][1], house[N][2])) << "\n";

	return 0;
}