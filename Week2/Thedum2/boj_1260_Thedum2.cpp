#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void ShowDFS(vector<short> *Pgraph,bool *visit,short StartNode) {

	//재귀함수를 이용해 구현 

	//현재 노드를 방문처리 후, 데이터 출력
	visit[StartNode] = true;
	cout << StartNode << " ";

	//인접 노드중 방문처리가 되지 않는 노드들을 재귀함수(스택)으로 처리
	for (int i = 0; i < Pgraph[StartNode].size(); i++) {
		if(!visit[Pgraph[StartNode][i]])
		ShowDFS(Pgraph, visit, Pgraph[StartNode][i]);
	}
}

void ShowBFS(vector<short>* Pgraph, bool* visit, short StartNode) {

	//그래프를 순회할 큐 하나 선언
	queue<short> BFSqueue;
	//첫번째 노드를 삽입하고, 방문처리
	BFSqueue.push(StartNode);
	visit[StartNode] = true;

	//큐가 빌때까지 반복
	while (!BFSqueue.empty()){
		int cmd = BFSqueue.front();
		cout << cmd << " ";
		BFSqueue.pop();
		//현재 front를 출력하고 pop하기!

		//현재 노드와 인접한 노드들을 순차적으로 큐에 삽입
		//방문처리가 되지 않는 것들만 push한다.
		for (int i = 0; i < Pgraph[cmd].size(); i++){
			short y = Pgraph[cmd][i];
			if (!visit[y]) {
				BFSqueue.push(y);
				visit[y] = true;
			}
		}
	}
}

int main(void) {

	//정점의 개수 N(1 ≤ N ≤ 1,000)
	//간선의 개수 M(1 ≤ M ≤ 10,000)
	//탐색을 시작할 정점의 번호 V
	short N, M, K;
	cin >> N >> M >> K;

	//노드는 1번부터 시작이니까 N+1 까지 선언
	//공간 낭비를 줄이기 위해서 동적으로 할당
	vector<short> *BOJgraph = new vector<short>[N + 1]();
	bool* DFSIsvisit = new bool[N + 1]{};
	bool* BFSIsvisit = new bool[N + 1]{};

	//그래프 연결시켜주기
	short X, Y;
	for (int i = 0; i < M; i++){
		cin >> X >> Y;
		BOJgraph[X].push_back(Y);
		BOJgraph[Y].push_back(X);
	}

	//방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
	//오름차순으로 Sort한다.
	for (int i = 1; i <= N; i++)
		sort(BOJgraph[i].begin(), BOJgraph[i].end());

	ShowDFS(BOJgraph, DFSIsvisit, K);
	cout << endl;
	ShowBFS(BOJgraph, BFSIsvisit, K);

	//동적 할당 후에는 무조건 해제
	delete[] BOJgraph;
	delete[] DFSIsvisit;
	delete[] BFSIsvisit;
}