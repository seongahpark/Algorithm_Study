[##_Image|kage@ekobzw/btrgBhfR1rA/eYVDrLHvpOVDqDDoMVWq31/img.png|alignCenter|data-origin-width="1500" data-origin-height="375" data-filename="1.png" data-ke-mobilestyle="widthOrigin"|||_##]

#### **난이도**

[##_Image|kage@beODvI/btrgOtL3r3V/vOMHZSViZHrgQpAGebWds0/img.jpg|alignLeft|data-origin-width="400" data-origin-height="512" width="69" height="89" data-ke-mobilestyle="widthOrigin"|||_##]

**Silver3**

---

**문제 링크**

**[https://www.acmicpc.net/problem/2606](https://www.acmicpc.net/problem/9093)**

---

## **문제 해결 과정**

**DFS, BFS와 같은 그래프 탐색 알고리즘을 이용하여 1번 컴퓨터부터 시작해서** 

**탐색하여, 그 탐색한 횟수를 검사해, 결과를 출력하였다.**

**BFS는 구현이 어렵고, 복잡하기 때문에, DFS를 이용해 알고리즘을 구성하였다.**

---

## **주의할 점**

**1.출력해야 할 값은 1번 컴퓨터를 통해서 감염된 컴퓨터의 수이므로, 1번 컴퓨터는 결과값에서 제외한다.**

**2.재귀함수 이용 시, 방문 처리를 잘 해주어 무한 루프에 빠지지 않도록 주의한다.**

---

## **코드**

```cpp
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
```

---

---

**잘못된 부분이나 오해할 수 있는 부분이 있다면 언제든지** 

**댓글 남겨주시기 바랍니다!**

![](https://t1.daumcdn.net/keditor/emoticon/niniz/large/006.gif)