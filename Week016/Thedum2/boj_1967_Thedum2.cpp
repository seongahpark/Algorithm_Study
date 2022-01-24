#include <iostream>
#include <vector>
#include <cstring>

#define endl "\n";

using namespace std;

//최대치 사이즈 10001 그래프,트리 사이즈
int TreeSize,Result,Lastnode;
vector<pair<int, int>> Tree[10001];
bool TreeVisit[10001];

void TreeDFS(int nownode, int nowcnt) {
	//만약 방문했다면 리턴
	if (TreeVisit[nownode]) return;
	//방문처리
	TreeVisit[nownode] = 1;
	//현재 가중치의 합보다 크다면
	if (Result < nowcnt) {
		//루트로부터 가장 먼 노드와 지름을 다시 설정
		Result = nowcnt;
		Lastnode = nownode;
	}
	//DFS실행
	for (int i = 0; i < Tree[nownode].size(); i++)
		TreeDFS(Tree[nownode][i].first, nowcnt + Tree[nownode][i].second);
}
int main() {
	cin >> TreeSize;
	int a, b, c;
	//그래프에 pair를 이용해 가중치까지 입력
	for (int i = 0; i < TreeSize-1; i++){
		cin >> a >> b >> c;
		Tree[a].push_back({ b,c });
		Tree[b].push_back({ a,c });
	}

	// 루트노드부터 먼 값 찾기
	TreeDFS(1, 0);

	//다음 탐색을 위해 초기화
	Result = 0;
	memset(TreeVisit, 0, sizeof(TreeVisit));

	//지름 구하기
	TreeDFS(Lastnode, 0);

	//지름 출력
	cout << Result << endl;
}
/*
### 1967 - 트리의 지름

- 트리가 아닌 그래프로 구현
- 먼저 DFS로 가장 먼 노드를 찾고, 거기서 dfs진행
*/