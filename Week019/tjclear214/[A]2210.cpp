#include <iostream>
#include <set>

using namespace std;

#define length 5

// Delta
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// Variables
set<int> result;
int arr[5][5] = { 0, };


/// <summary>
/// DFS
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="cnt">탐색 횟수</param>
/// <param name="builder">결과 빌더</param>
void dfs(int x, int y, int cnt, int builder)
{
	if (cnt == length)
	{
		result.insert(builder);
		return;
	}

	// 4방향 탐색
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= length || ny < 0 || ny >= length)
		{
			continue;
		}

		dfs(nx, ny, cnt + 1, builder * 10 + arr[ny][nx]);
	}
}

int main()
{
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++) cin >> arr[i][j];
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++) dfs(j, i, 0, arr[i][j]);

	cout << result.size() << "\n";

	return 0;
}