#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//움직임을 표현할 X,Y이동 배열.
int moveX[4] = { -1,0,1,0 };
int moveY[4] = { 0,-1,0,1 };

//맵 크기를 저장할 변수
//세로 길이 N(1 ≤ N ≤ 100)과 가로 길이 M(1 ≤ M ≤ 100)
//그리고 음식물 쓰레기의 개수 K(1 ≤ K ≤ N×M)
int N, M,K;

//가장 큰 쓰레기를 담은 변수
int result=0;

void ShowBFS(vector<bool>* map, vector<bool>* visit, int a, int b) {
	//map를 BFS할 Queue하나 선언 
	//좌표를 표현해야 하므로 pair를 이용
	queue<pair<int, int>> MapQueue;
	//시작 페어를 입력 받음
	MapQueue.push({ a,b });
	visit[a][b] = true;

	//병사가 몇명인지 카운트할 변수 선언
	int cnt=0;

	//Queue가 빌 때까지 반복
	while (!MapQueue.empty()) {

		pair<int, int> cmd = MapQueue.front();
		MapQueue.pop();
		cnt++;

		//다음 좌표로 이동, 총 4개의 좌표, 상하좌우
		for (int i = 0; i < 4; i++) {
			//다음 이동 좌표
			int nextX = cmd.first + moveX[i];
			int nextY = cmd.second + moveY[i];
			if (nextX >= 0 && nextY >= 0 && nextX <N && nextY < M) {//map의 범위를 벗어나지 않게
				if (!visit[nextX][nextY] && map[nextX][nextY]) {
					//다음 BFS을 위해 현재 좌표 QUEUE에 Push!
					MapQueue.push({ nextX ,nextY });
					visit[nextX][nextY] = true;
				}
			}
		}
	}
	//만일 이번 탐색값이 기존의 값보다 크다면
	if (cnt > result)
		result = cnt;
}

int main(void) {

	//맵 크기 입력받음
	cin >> N >> M >> K;

	//가로와 세로를 주의해서 세로 크기로 벡터 배열 선언
	//음식물이 있고, 없고 둘중 하나이므로 bool형 사용
	vector<bool>* BOJmap = new vector<bool>[N](); {}
	vector<bool>* Mapvisit = new vector<bool>[N];

	//음식물의 위치를 저장할 좌표 변수 
	int X, Y;

	//방문을 저장할 벡터 크기 조정, 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Mapvisit[i].push_back(0);
			BOJmap[i].push_back(0);
		}
	}

	//음식물의 위치에 1을 저장
	for (int i = 0; i < K; i++){
		cin >> X >> Y;
		BOJmap[X - 1][Y - 1]=1;		
	}
	
	//BFS함수를 돌리고
	//맵의 맨 끝까지의 시작노드로 두면서 탐색
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if(!Mapvisit[i][j] && BOJmap[i][j])//방문하지 않고 음식물이 있는 노드에만 진행
			ShowBFS(BOJmap, Mapvisit, i, j);
		}
	}

	cout << result;
}