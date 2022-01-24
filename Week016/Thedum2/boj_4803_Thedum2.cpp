#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//테스트 케이스마다 초기화 시켜서 사용할거임
vector<int> BOJtree[501];
bool BOJvisit[501];
int TestCase = 0;
int result = 0;

bool BOJDFS(int start,int postx) {
	//방문처리
	BOJvisit[start] = true;

	for (int i = 0; i < BOJtree[start].size(); i++)
	{
		//연결된 노드가 없을 때
		if (BOJtree[start][i] == postx) continue;
		//연결된 노드가 방문했을때
		if (BOJvisit[BOJtree[start][i]]) return false;
		
		if (BOJDFS(BOJtree[start][i], start) == false) return false;
	}
	return true;
}

int main() {
	int N, M;

	while (true){
		//만약 0 0 이면 그만
		cin >> N >> M;
		if (!(N || M)) break;

		//다음 테스트 케이스를 위한 초기화
		for (int i = 1; i <= 500; i++){
			BOJtree[i].clear();
			BOJvisit[i] = 0;
		}
		TestCase++;
		result = 0;

		//간선정보 입력
		int a, b;
		for (int i = 0; i < M; i++){
			cin >> a >> b;
			BOJtree[a].push_back(b);
			BOJtree[b].push_back(a);
		}

		//DFS실행
		for (int i = 1; i <= N; i++)
			if (!BOJvisit[i])
				if (BOJDFS(i, 0))
					result++;

		//결과 출력
		cout << "Case " << TestCase << ": ";
		if (result > 1)
			cout << "A forest of " << result << " trees." << '\n';
		else if (result == 1)
			cout << "There is one tree." << '\n';
		else if (result == 0)
			cout << "No trees." << '\n';
	}


}

/*
### 4803 - 트리

- 그래프를 통해 구현,DFS를 돌아서 사이클 개수 파악
- if (!(N || M)) break;
*/