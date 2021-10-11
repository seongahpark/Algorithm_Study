#include <iostream>
#include <queue>
using namespace std;

//이미 방문한 수인지 체크하는 배열
bool Check[100001] = {false,};
const int MAX = 100000;

void Hide_AND_Seek(int Subin,int Sister) {
	//수빈이가 갈 수 있는 모든 경우의 수를 저장할 큐
	queue<pair<int,int>> ABAB;
	ABAB.push({ Subin,0 });
	Check[Subin] = true;

	while (!ABAB.empty())	{
		int number = ABAB.front().first;
		int cnt = ABAB.front().second;
		ABAB.pop();

		if (number == Sister) {
			cout << cnt;
			return;
		}
		//수빈이가 순간이동을 하는 경우
		if (number * 2 <= 100000&& !Check[number * 2]) {
			ABAB.push({ number * 2,cnt + 1 });
			Check[number * 2] = true;
		}
		//수빈이가 앞으로 한칸 가는 경우
		if (number + 1 <= MAX && !Check[number + 1]) {
			ABAB.push({ number + 1,cnt + 1 });
			Check[number + 1] = true;
		}
		//수빈이가 뒤로 한칸 가는 경우
			if (number >0 && !Check[number - 1]) {
				ABAB.push({ number - 1,cnt + 1 });
				Check[number - 1] = true;
		}

	}

}

int main() {
	int N, K;
	cin >> N >> K;
	Hide_AND_Seek(N,K);
}