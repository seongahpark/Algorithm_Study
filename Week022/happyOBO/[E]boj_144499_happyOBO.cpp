#include <bits/stdc++.h>

using namespace std;

struct Dice;
enum class Direction : int
{
	East = 1,
	West = 2,
	North = 3,
	South = 4,
};

void solution(int N, int M, Dice dice, queue<Direction>& commands);

const int MAXSIZE = 20;
int board[MAXSIZE][MAXSIZE] = {};

struct Dice
{
	Dice(int posx, int posy) { x = posx; y = posy; }
	int x, y;
	int top = 0;
	int bottom = 0;
	int sides[4] = {}; 
	
	map<Direction, pair<int, int>> MoveIdx = { {Direction::East, {1,3}}, {Direction::West, {3,1}}, {Direction::North,{0,2}}, {Direction::South,{2,0}} };
	map<Direction, pair<int, int>> MoveCoord = { {Direction::East, {0,1}}, {Direction::West, {0,-1}}, {Direction::North,{-1,0}}, {Direction::South,{1,0}} };

	bool canMove(int N, int M, Direction DirCommand)
	{
		int posx = x + MoveCoord[DirCommand].first;
		int posy = y + MoveCoord[DirCommand].second;

		if (posx < 0 || N <= posx)
			return false;
		if (posy < 0 || M <= posy)
			return false;

		return true;

	}
	void Move(Direction DirCommand)
	{
		int tmp = bottom;
		bottom = sides[MoveIdx[DirCommand].first];
		sides[MoveIdx[DirCommand].first] = top;
		top = sides[MoveIdx[DirCommand].second];
		sides[MoveIdx[DirCommand].second] = tmp;
		x += MoveCoord[DirCommand].first;
		y += MoveCoord[DirCommand].second;
	}

	int getTop()
	{
		return top;
	}

	int getBottom()
	{
		return bottom;
	}

	void setBottom(int value)
	{
		bottom = value;
	}


};



int main() {
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;
	queue<Direction> commands;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}

	}

	for (int i = 0; i < K; i++)
	{
		int dir;
		cin >> dir;
		commands.push(static_cast<Direction>(dir));
	}

	solution(N, M, Dice(x,y), commands);
}

void solution(int N, int M, Dice dice, queue<Direction>& commands)
{
	while (!commands.empty())
	{
		Direction cmd = commands.front();
		commands.pop();

		if (dice.canMove(N,M,cmd))
		{
			dice.Move(cmd);
			cout << dice.getTop() << "\n";

			if (board[dice.x][dice.y] == 0)
			{
				board[dice.x][dice.y] = dice.getBottom();
			}
			else
			{
				dice.setBottom(board[dice.x][dice.y]);
				board[dice.x][dice.y] = 0;
			}
		}
	}
}

