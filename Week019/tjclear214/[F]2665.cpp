#include <iostream>
#include <queue>


using namespace std;

struct coord
{
	int x;
	int y;
};

// Delta
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// Variables
int arr[51][51] = { 0, };
int dv[51][51] = { 0, }; // distance value


int main()
{
	// n 입력
	int n = 0;
	cin >> n;

	// 맵 입력
	string line;
	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < line.length(); j++)
		{
			arr[i][j] = line[j] - '0'; // 문자열을 정수형으로
			dv[i][j] = 2501; // dv 초기 값은 무한 (max * max) + 1
		}
	}

	// 탐색 변수 정의
	int x = 0, y = 0;
	dv[0][0] = 0;

	queue<coord> q;
	coord start = { 0, 0 };
	q.push(start);

	// BFS 탐색 시작
	while (!q.empty())
	{
		coord target = q.front();
		x = target.x;
		y = target.y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			coord tmp = { nx, ny };

			// 더 효율적인 dv 값이 있다면 덮어 쓴다.
			// 다음 방이 검은방인 경우 이전 방에서 +1 한 값이 다음 방의 dv 값보다 작으면 덮어 쓰면 된다.
 			if (arr[ny][nx] == 0 && dv[ny][nx] > dv[y][x] + 1) // 검은 방
			{
				dv[ny][nx] = dv[y][x] + 1;
				q.push(tmp);
			}
			else if (arr[ny][nx] == 1 && dv[ny][nx] > dv[y][x]) // 흰방
			{
				dv[ny][nx] = dv[y][x];
				q.push(tmp);
			}
			else continue;
		}
	}


	cout << dv[n - 1][n - 1];
	return 0;
}