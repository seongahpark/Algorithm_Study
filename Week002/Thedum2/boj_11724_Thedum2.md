[##_Image|kage@bq1y7K/btrgFSsAS8M/nMicHUiGYdeJjFOBJ7z1mk/img.png|alignCenter|data-origin-width="1500" data-origin-height="375" data-filename="2.png" data-ke-mobilestyle="widthOrigin"|||_##]

#### **난이도**

[##_Image|kage@b0q7UR/btrgFS7az9T/BtBa3SZWzPHUhshwMhnAr0/img.jpg|alignLeft|data-origin-width="400" data-origin-height="512" width="95" height="122" data-ke-mobilestyle="widthOrigin"|||_##]

**SIlver2**

---

**문제 링크**

**[https://www.acmicpc.net/problem/11724](https://www.acmicpc.net/problem/9093)**

---

## **문제 해결 과정**

**반복문을 통해 1번 노드부터 노드의 개수만큼 시작 노드 로 두고, DFS탐색을 진행하였다.**

**시작노드가 이미 방문된 노드라면, PASS하고 아니라면 결과값에 +1을 더해준다.**

**반복문이 끝났을 때, 결과값을 출력한다.**

---

## **주의할 점**

**1.간선으로 연결되지 않은, 혼자 있는 노드의 경우도 체크해 주어야 한다.**

**2.무방향 그래프라는 점은 잘 인지하고, 그래프를 구현해야 한다**

---

## **코드**

```cpp
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
```

---

---

**잘못된 부분이나 오해할 수 있는 부분이 있다면 언제든지** 

**댓글 남겨주시기 바랍니다!**

![](https://t1.daumcdn.net/keditor/emoticon/niniz/large/006.gif)