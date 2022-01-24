#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define endl "\n";

using namespace std;

//최대치 사이즈 10001 그래프,트리 사이즈
int TreeSize,Result,Lastnode;
vector<pair<int, int>> Tree[100001];
bool TreeVisit[100001];

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

	for (int i = 1; i <= TreeSize; i++){
		int a, b,c,temp;
		//first or second를 구별
		bool order=false;
		//몇번 노드인가?
		cin >> a;
		while (true){
			//수 하나 입력받고, -1이라면 NAGA
			cin >> temp;
			if (temp == -1) break;
			//order가 false라면 앞에, 아니면 뒤에 저장 후 벡터 삽입
			if (!order) { b = temp; order = 1; }
			else { c = temp; 
			order = 0;
			Tree[a].push_back({ b,c });
			}
		}
	}
	//순서대로 라는 말이 없어서
	for (int i = 0; i < 100001; i++)
		sort(Tree[i].begin(), Tree[i].end());

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
### 1167 - 트리의 지름

- 적은 순서대로 라는 말이 없어서 sort
- 그래프이용
- 1991과 같은 문제
*/