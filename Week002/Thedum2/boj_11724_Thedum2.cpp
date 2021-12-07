#include <iostream>
#include <vector>
using namespace std;

//구현이 비교적 간단한 DFS를 이용하였다.
void DFSDFS(vector<int> *Pvec,bool* visit,short StartNode) {

	//현재 노드의 방문 처리
	visit[StartNode] = true;

	//현재 노드의 인접 노드 중 방문처리가 되지 않은 노드를 재귀함수로 방문
	for (int i = 0; i < Pvec[StartNode].size(); i++)
		if (!visit[Pvec[StartNode][i]])
			DFSDFS(Pvec, visit, Pvec[StartNode][i]);
}
int main() {
	//정점의 개수 N과 간선의 개수 M
	int N,M;
	cin >> N >> M;

	//동적 할당을 이용해서 필요한 만큼만 메모리 공간 생성
	vector<int>* BOJgraph = new vector<int>[N + 1]();
	bool* isvisit = new bool[N + 1]{};

	int X, Y;
	//간선 개수만큼 반복, 무방향 그래프의 연결
	for (int i = 0; i < M; i++){
		cin >> X >> Y;
		BOJgraph[X].push_back(Y);
		BOJgraph[Y].push_back(X);
	}
	//연결 요소의 개수
	int result=0;
	//1번 노드부터 DFS 실행, 방문되지 않는 노드만 실행.
	for (int i = 1; i <= N; i++){
		if (!isvisit[i]) {//DFS가 실행 가능하다는 것은 새로운 영역이라는 뜻이다.
			result++;
			DFSDFS(BOJgraph, isvisit, i);
		}
	}

	cout << result;
	//정답 출력

	//메모리 공간 해제
	delete[] BOJgraph;
	delete[] isvisit;
}