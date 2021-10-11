#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//움직임을 표현할 X,Y이동 배열.
int moveX[4] = { -1,0,1,0 };
int moveY[4] = { 0,-1,0,1 };

//아군 병사와 적군 병사의 위력을 저장할 변수 출력
int Player = 0, Enemy = 0;

//맵 크기를 저장할 변수
int N, M;

void ShowBFS(vector<bool>* map, vector<bool>* visit, int a, int b,bool who) {
	//map를 BFS할 Queue하나 선언 
	//좌표를 표현해야 하므로 pair를 이용
	queue<pair<int, int>> MapQueue;
	//시작 페어를 입력 받음
	MapQueue.push({ a,b });
	visit[a][b] = true;

	//병사가 몇명인지 카운트할 변수 선언
	int cnt=1;

	//Queue가 빌 때까지 반복
	while (!MapQueue.empty()) {

		pair<int, int> cmd = MapQueue.front();
		MapQueue.pop();

		//다음 좌표로 이동, 총 4개의 좌표, 상하좌우
		for (int i = 0; i < 4; i++) {
			//다음 이동 좌표
			int nextX = cmd.first + moveX[i];
			int nextY = cmd.second + moveY[i];
			if (nextX >= 0 && nextY >= 0 && nextX <M && nextY < N) {//map의 범위를 벗어나지 않게
				if ((!visit[nextX][nextY]) && (map[nextX][nextY] ==who)) {
					//다음 BFS을 위해 현재 좌표 QUEUE에 Push!
					MapQueue.push({ nextX ,nextY });
					cnt++;
					visit[nextX][nextY] = true;
				}
			}
		}
	}
	if (who)Player += cnt * cnt;
	else	Enemy += cnt * cnt;
}

int main(void) {

	//맵 크기 입력받음
	cin >> N >> M;

	//아군 병사 W, 적군 병사 B를 저장할 벡터와, 이를 방문검사할 벡터
	vector<bool>* BOJmap = new vector<bool>[M](); {}
	vector<bool>* Mapvisit = new vector<bool>[M](); {}

	string cmd;
	for (int i = 0; i < M; i++) {
		cin >> cmd;
		for (int j = 0; j < N; j++) {
			BOJmap[i].push_back(cmd[j]=='W'?1:0);
			Mapvisit[i].push_back(false);
		}
	}

	
	//BFS함수를 탐색되지 않은 시작점마다 모두 돌려서 전체를 탐색한다,
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			if(!Mapvisit[i][j])
			ShowBFS(BOJmap, Mapvisit, i, j, BOJmap[i][j]);
		}
	}

	cout << Player << " " << Enemy;
	
}