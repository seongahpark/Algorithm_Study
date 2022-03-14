#include <bits/stdc++.h>

using namespace std;

void solution();
void backtrk(pair<int, int> currPos, map<int, int>& squares);
void updateCurrPos(pair<int, int>& currPos);
bool isEmpty(pair<int, int>& pos, int Size);
void fillBoard(pair<int, int>& pos, int Size, bool value);

const int MAXSIZE = 5;
const int BOARDSIZE = 10;
int board[BOARDSIZE][BOARDSIZE];
int result = INT_MAX;

bool visited[BOARDSIZE][BOARDSIZE] = {};

int main() {

	for (int i = 0; i < BOARDSIZE; i++)
		for (int j = 0; j < BOARDSIZE; j++)
			cin >> board[i][j];
	solution();
}


void solution()
{
	map<int,int> squares = { {1,MAXSIZE},{2,MAXSIZE} ,{3,MAXSIZE} ,{4,MAXSIZE},{5,MAXSIZE}};
	backtrk({ 0,0 }, squares);
	if (result == INT_MAX)
		cout << -1;
	else
		cout << result;
	return;
}

void backtrk(pair<int,int> currPos, map<int,int>& squares)
{
	updateCurrPos(currPos);
	if (currPos.first == -1 && currPos.second == -1)
	{

		int tmp = 0;
		for_each(squares.begin(), squares.end(), [&tmp](pair<const int, int>& square) {tmp += (MAXSIZE - square.second); });
		result = min(tmp, result);
		return;
	}
	for (auto& square : squares)
	{
		if (0 < square.second && isEmpty(currPos, square.first))
		{
			fillBoard(currPos, square.first, true);
			square.second--;
			backtrk(currPos, squares);
			square.second++;
			fillBoard(currPos, square.first, false);

		}
	}
}

// 다음에 탐색할 위치로 업데이트
void updateCurrPos(pair<int, int>& currPos)
{

	for (int k = currPos.first * currPos.second; k < BOARDSIZE * BOARDSIZE; k++)
	{
		int i = k / BOARDSIZE;
		int j = k % BOARDSIZE;
		if (board[i][j] == 1 && !visited[i][j])
		{
			currPos = { i,j };
			return;
		}
	}


	currPos = { -1,-1 };
}

// pos 위치로부터 Size 크기인 종이를 놓을수 있는지 확인
bool isEmpty(pair<int, int>& pos, int Size)
{
	if (BOARDSIZE < pos.first + Size) return false;
	if (BOARDSIZE < pos.second + Size) return false;

	for(int i = pos.first; i < pos.first + Size; i++)
		for (int j = pos.second; j < pos.second + Size; j++)
		{
			if (visited[i][j]) return false;
			if (board[i][j] == 0) return false;
		}
	return true;
 }

// pos 위치로부터 Size 크기만큼 value 값으로 채우기
void fillBoard(pair<int, int>& pos, int Size, bool value)
{
	for (int i = pos.first; i < pos.first + Size; i++)
		for (int j = pos.second; j < pos.second + Size; j++)
			visited[i][j] = value;


}