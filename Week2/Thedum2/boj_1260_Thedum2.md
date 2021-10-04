[##_Image|kage@bLHV4a/btrgCE8Ggrp/oE8QISKIkcXX5Q6qyexYS0/img.png|alignCenter|data-origin-width="1500" data-origin-height="375" data-filename="asdasdasdas.png" data-ke-mobilestyle="widthOrigin"|||_##]

---

#### **난이도**

[##_Image|kage@dvsMye/btrgA6d9zLb/4A8FGpES99BO6YedZAqRZk/img.jpg|alignLeft|data-origin-width="400" data-origin-height="512" width="73" data-ke-mobilestyle="widthOrigin"|||_##]

**Silver2**

---

**문제 링크**

**[https://www.acmicpc.net/problem/1260](https://www.acmicpc.net/problem/9093)**

---

## **문제 해결 과정**

**BFS, DFS의 기본 동작을 이해하고, 함수를 제작 후,**

**출력 형식에 맞추어 출력하면 된다.**

**STL의 사용이 필수!**

---

## **주의할 점**

**1.정점이 여러 개라면, 가장 작은 노드부터 탐색해야 하므로, 정렬을 해주어야 한다.**

**2.동적 할당을 이용한다면, 포인터 이용과 메모리 해제에 주의하자.**

---

## **코드**

```cpp
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
	delete BOJgraph;
	delete DFSIsvisit;
	delete BFSIsvisit;
}
```

---

---

**잘못된 부분이나 오해할 수 있는 부분이 있다면 언제든지** 

**댓글 남겨주시기 바랍니다!**

![](https://t1.daumcdn.net/keditor/emoticon/niniz/large/006.gif)