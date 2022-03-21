#include <iostream>
#include <queue>
const int MAX = 1001;
using namespace std;

int n, w, l; // n 트럭개수, w 단위길이, l 최대하중
int arr[MAX];
int res = 0, curWeight = 0;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) {
				curWeight -= q.front();
				q.pop();
			}
			if (curWeight + arr[i] <= l) break;
			q.push(0);
			res++;
		}
		//while문 보다 처음에 넣어주면 다음 트럭이 바로 들어와버려
		//최대 하중이 넘어가는 일이 발생함
		q.push(arr[i]);
		curWeight += arr[i];
		res++;
	}
	//마지막껀 계산이 안됐기 때문
	cout << res + w;
	return 0;
}