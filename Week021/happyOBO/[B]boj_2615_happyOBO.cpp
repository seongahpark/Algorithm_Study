#include <bits/stdc++.h>

using namespace std;


enum FieldType : int
{
	EMPTY = 0,
	BLACK = 1,
	WHITE = 2,
};

void solution();
int getLength(pair<int, int> start, pair<int, int> dir);

const int MAXSIZE = 20;
const int DESIREDLENGTH = 5;
FieldType board[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE] = {};


int main() {
	for(int i = 1; i < MAXSIZE; i++)
		for (int j = 1; j < MAXSIZE; j++)
		{
			int f;
			cin >> f;
			board[i][j] = static_cast<FieldType>(f);
		}

	solution();
}


void solution()
{
	pair<int, int> Directions[4] = { {1,0} , {0,1} , {1,1}, {1,-1} };

	for (auto& dir : Directions)
	{
		for (int i = 1; i < MAXSIZE; i++)
			for (int j = 1; j < MAXSIZE; j++)
			{
				if (board[i][j] != EMPTY && !visited[i][j])
				{
					if (DESIREDLENGTH == getLength({ i,j }, dir))
					{
						if (dir == Directions[3])
						{
							// 아래 왼쪽 방향은 끝부분 위치 출력
							cout << board[i][j] << "\n";
							cout << i + (DESIREDLENGTH -1)<< " " << j - (DESIREDLENGTH -1);
							return;
						}
						else
						{
							cout << board[i][j] << "\n";
							cout << i << " " << j;
							return;

						}
					}
				}
			}

		fill(&visited[0][0], &visited[MAXSIZE - 1][MAXSIZE], false);
	}

	cout << 0;
	return;
}


int getLength(pair<int, int> start, pair<int, int> dir)
{
	pair<int, int> curr = start;
	int counter = 0;
	while (curr.first < MAXSIZE && curr.second < MAXSIZE &&
		board[curr.first][curr.second] == board[start.first][start.second])
	{
		visited[curr.first][curr.second] = true;
		counter++;
		curr.first += dir.first;
		curr.second += dir.second;
	}
	return counter;
}