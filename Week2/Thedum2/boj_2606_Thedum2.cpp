#include <iostream>
#include <vector>
using namespace std;

//1번 컴퓨터를 통해 감염되는 컴퓨터의 숫자
int result=0;

//구현이 비교적 간단한 DFS를 이용하였다.
void WormVirus(vector<short> *Pvec,bool* visit,short StartNode) {

	//현재 노드의 방문 처리
	visit[StartNode] = true;
	//방문하였다면, 감염된 컴퓨터이므로 result를 하나 더해준다.
	result++;

	//현재 노드의 인접 노드 중 방문처리가 되지 않은 노드를 재귀함수로 방문
	for (int i = 0; i < Pvec[StartNode].size(); i++)
		if (!visit[Pvec[StartNode][i]])
			WormVirus(Pvec, visit, Pvec[StartNode][i]);
}
int main() {
	//컴퓨터의 개수, 연결 간선의 개수
	short comcount,comconnect;
	cin >> comcount >> comconnect;

	//동적 할당을 이용해서 필요한 만큼만 메모리 공간 생성
	vector<short>* Computor = new vector<short>[comcount + 1]();
	bool* isvisit = new bool[comcount + 1]{};

	short X, Y;
	//간선 개수만큼 반복
	for (int i = 0; i < comconnect; i++){
		cin >> X >> Y;
		Computor[X].push_back(Y);
		Computor[Y].push_back(X);
	}

	//그래프 연결 후  1번 컴퓨터부터 DFS실행
	WormVirus(Computor, isvisit, 1);
	//1번 컴퓨터를 통해 감염된 컴퓨터의 숫자이므로 1번 컴터는 제외!
	cout << result-1;

	//메모리 공간 해제
	delete[] Computor;
	delete[] isvisit;
}