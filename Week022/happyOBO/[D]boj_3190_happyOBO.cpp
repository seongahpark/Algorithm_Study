#include <bits/stdc++.h>

using namespace std;

void solution(int N, queue<pair<int, int>>& route);
bool collisionWall(int N, pair<int, int>& curr);
bool collisionSnake(pair<int, int>& curr);

enum Field : int
{
	Empty = 0,
	Apple = 1,
	Snake = 2,
};


const int MAXSIZE = 101;
Field graph[MAXSIZE][MAXSIZE] = {};

// 증가 반시계 방향 , 감소 시계 방향 : UP LEFT DOWN RIGHT
pair<int, int> Directions[] = { {-1, 0} , {0,-1}, {1,0}, {0,1} };


int main() {
	int N, K, L;
	queue<pair<int,int>> q;
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		graph[r][c] = Apple;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int timer;
		char dir;
		cin >> timer >> dir;
		if (dir == 'L') q.push({timer, 1});
		if (dir == 'D') q.push({timer, -1});

	}
	solution(N, q);
}

void solution(int N, queue<pair<int, int>>& route)
{
	// front : 앞머리 , back : 꼬리
	deque<pair<int, int>> snake;
	snake.push_front({ 1,1 });
	int dir;
	if (route.front().second == 1) dir = 2;
	else dir = 3;
	int timer = 0;
	while (true)
	{
		// 다음 이동 방향을 위해 방향 체크
		if (!route.empty() && timer == route.front().first)
		{
			dir = (dir + route.front().second + 4) % 4;
			route.pop();
		}
		timer++;

		pair<int, int> next = { snake.front().first + Directions[dir].first , snake.front().second + Directions[dir].second };

		// 충돌 체크
		if (collisionWall(N, next)) break;

		// 사과 체크
		if (graph[next.first][next.second] == Empty)
		{
			graph[snake.back().first][snake.back().second] = Empty;
			snake.pop_back();
		}

		// 충돌 체크
		if (collisionSnake(next)) break;

		snake.push_front(next);
		graph[next.first][next.second] = Snake;
	}

	cout << timer;
}

bool collisionWall(int N, pair<int, int>& curr)
{
	if (curr.first <= 0 || N < curr.first)
		return true;
	if (curr.second <= 0 || N < curr.second)
		return true;
	return false;
}

bool collisionSnake(pair<int, int>& curr)
{
	return graph[curr.first][curr.second] == Snake;
}
