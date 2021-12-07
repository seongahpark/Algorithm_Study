#include <iostream>
#include <queue>
using namespace std;

//10^9 까지가 범위이므로 이를 수용할 수 있는 long형 채택
long A, B;

void A_TO_B(long cmd,long answer) {
	//BFS 탐색을 위한 큐 하나 선언
	//현재 진행 상황을 저장할 변수와 얼마나 시도했는지를
	//저장하는 int현 변수 선언
	queue<pair<long,int>> ABAB;
	//초기값은 A와 1
	ABAB.push({ cmd,1 });
	
	//큐가 빌 때까지 최대치를 넘지 않는 범위 내에서
	//두가지 연산의 결과를 다시 큐에 넣는다.
	while (!ABAB.empty())	{
		long number = ABAB.front().first;
		int cnt = ABAB.front().second;
		ABAB.pop();
		//중간에 조건문에 걸리면 성공!
		if (number == answer) {
			cout << cnt;
			return;
		}
		if(number * 2<=answer)
		ABAB.push({ number * 2,cnt + 1 });
		if (number * 10 +1 <=answer)
		ABAB.push({ number * 10+1,cnt + 1 });

	}
	//종료시까지 아무것도 안걸렸다면 -1 출력
	cout << -1;
	return;

}

int main() {
	cin >> A >> B;
	A_TO_B(A, B);
}