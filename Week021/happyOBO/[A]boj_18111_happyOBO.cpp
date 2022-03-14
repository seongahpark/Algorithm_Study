#include <bits/stdc++.h>

using namespace std;

void solution(int N, int M, int inventoryBlocks);
void calcBlockCount(int N, int M, int inventoryBlocks, int& totalBlocks, int& minHeight, int& maxHeight);
int getBuildTime(int N, int M, int targetHeight);

const int MAXSIZE = 500;
int board[MAXSIZE][MAXSIZE] = {};

int main() {
	int N, M, B;
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	solution(N, M, B);
}


void solution(int N, int M, int inventoryBlocks)
{
	int resultTime = INT_MAX, resultHeight = INT_MIN;
	int totalBlocks, minHeight, maxHeight;
	calcBlockCount(N, M, inventoryBlocks, totalBlocks, minHeight, maxHeight);
	maxHeight = min(maxHeight, totalBlocks / (N * M));

	for (int h = minHeight; h <= maxHeight; h++)
	{
		int t = getBuildTime(N, M, h);
		if (t < resultTime)
		{
			resultTime = t;
			resultHeight = h;
		}
		else if (t == resultTime) resultHeight = max(resultHeight, h);
	}

	cout << resultTime << " " << resultHeight;
}

void calcBlockCount(int N, int M,int inventoryBlocks, int& totalBlocks, int& minHeight, int& maxHeight)
{
	totalBlocks = inventoryBlocks;
	minHeight = INT_MAX;
	maxHeight = INT_MIN;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			totalBlocks += board[i][j];
			minHeight = min(board[i][j], minHeight);
			maxHeight = max(board[i][j], maxHeight);
		}
}

int getBuildTime(int N, int M, int targetHeight)
{
	int t = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (targetHeight == board[i][j]) continue;
			else if (targetHeight < board[i][j]) t += (board[i][j] - targetHeight) * 2;
			else t += (targetHeight - board[i][j]);
		}

	return t;
}