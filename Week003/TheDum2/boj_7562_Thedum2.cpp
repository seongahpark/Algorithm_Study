#include <iostream>
#include <queue>
using namespace std;

//나이트의 움직임을 계산할 X,Y축 배열 선언
int MOVEX[8] = { -2,-1,1,2,-2,-1,1,2 };
int MOVEY[8] = { -1,-2,-2,-1,1,2,2,1 };

void GO_GO_Knight(vector <bool> *Chessmap,pair<int,int> start, pair<int, int> end,int mapsize) {
	
	//현재 위치를 저장할 페어 하나와 몇번 갔는지 
	//체크하는 int형 변수 하나를 페어로 묶어서
	//큐로 저장한다.
	queue<pair<pair<int, int>, int>> Chess;
	Chess.push({ start, 0 });
	Chessmap[start.first][start.second] = true;
	//최초 노드 방문 처리

	while (!Chess.empty())	{
		//첫번쨰 - 첫번째가 x, 첫번쨰 - 두번째가 y이다.
		int x = Chess.front().first.first;
		int y = Chess.front().first.second;
		int cnt = Chess.front().second;
		Chess.pop();
		
		//도착한다면!
		if (x == end.first && y == end.second) {
			cout << cnt<<"\n";
			return;
		}

		//나이트가 갈 수 있는 경우의 수는 8가지이다
		for (int i = 0; i < 8; i++){
			//다음 위치 
			int Nextx = x + MOVEX[i];
			int Nexty = y + MOVEY[i];
			//맵의 크기를 벗어나지 않는 선에서
			if (Nextx >= 0 && Nextx < mapsize && Nexty >= 0 && Nexty < mapsize) {
				if (!Chessmap[Nextx][Nexty]) {//방문을 하지 않았던 위치만 방문
					Chess.push({ {Nextx ,Nexty }, cnt + 1 });//카운트를 늘리고 다음 경우 push
					Chessmap[Nextx][Nexty] = true;//방문처리
				}
			}
		}

	}

}

int main() {
	int repeat;
	cin >> repeat;

	int Size;//맵의 크기
	pair<int, int> KnightStart, KnightEnd;//시작, 도착점

	//테스트 케이스만큼 반복
	for (int i = 0; i < repeat; i++)	{
		cin >> Size;
		cin >> KnightStart.first >> KnightStart.second;
		cin >> KnightEnd.first >> KnightEnd.second;
		//방문 처리만 하면 되므로 bool형 벡터 하나 선언
		//동적 할당을 통해 크기만큼만 선언
		vector<bool>* map = new vector<bool>[Size]();
		
		//0으로 벡터 크기만큼 초기화
		for (int i = 0; i < Size; i++)
			for (int j = 0; j < Size; j++)
				map[i].push_back(0);
		//함수 호출
		GO_GO_Knight(map, KnightStart, KnightEnd,Size);
		//메모리 해제
		delete[] map;
	}
}