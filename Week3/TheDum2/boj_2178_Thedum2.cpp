#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//움직임을 표현할 X,Y이동 배열.
int moveX[4] = { -1,0,1,0 };
int moveY[4] = { 0,-1,0,1 };

//0,0부터의 거리를 저장할 변수 선언
short mazecount[101][101]{};

void ShowBFS(vector<bool>* maze, vector<bool>* visit,int n,int m) {

	//maze를 BFS할 Queue하나 선언 
	//좌표를 표현해야 하므로 pair를 이용
	queue<pair<int, int>> MazeQueue;
	//최초의 pair는 0,0
	MazeQueue.push({0,0});
	visit[0][0] = true;

	//Queue가 빌 때까지 반복
	while (!MazeQueue.empty()){
		pair<int, int> cmd = MazeQueue.front();
		MazeQueue.pop();

		//다음 좌표로 이동, 총 4개의 좌표, 상하좌우
		for (int i = 0; i < 4; i++){
			//다음 이동 좌표
			int nextX= cmd.first + moveX[i];
			int nextY= cmd.second + moveY[i];
			if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < m) {//maze의 범위를 벗어나지 않게
				if ((!visit[nextX][nextY]) && (maze[nextX][nextY] == 1)) {//다음 좌표의 값이 1이고, 방문하지 않았을 때
					//0,0부터 현재 좌표까지의 거리(결과값 배열)
					mazecount[nextX][nextY] = mazecount[cmd.first][cmd.second]+1;
					//다음 BFS을 위해 현재 좌표 QUEUE에 Push!
					MazeQueue.push({ nextX ,nextY });
					visit[nextX][nextY] = true;
					
				}
			}
		}
	}
}

int main(void) {

	int N, M;
	cin >> N >> M ;

	//미로와 방문을 체크할 벡터 선언 0과1만 있으면 되므로 bool형으로
	vector<bool>* BOJmaze = new vector<bool>[N](); {}
	vector<bool>* Mazevisit = new vector<bool>[N](); {}

	string cmd;
	for (int i = 0; i < N; i++)	{
		cin >> cmd;
		for (int j = 0; j < M; j++){
			BOJmaze[i].push_back(cmd[j] - 48);//ASCII CODE의 성질을 이용해서, 0이나1 삽입
			Mazevisit[i].push_back(false);
		}
	}

	//BFS함수를 돌리고
	//미로의 맨 끝까지의 거리 출력
	ShowBFS(BOJmaze, Mazevisit, N, M);
	cout << mazecount[N - 1][M - 1]+1;
}