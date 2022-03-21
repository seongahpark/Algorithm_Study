#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
bool visited[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int res;

queue<pair<int, char>> d; //dir
queue<pair<int, int>> s; //snake
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, l;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		arr[a-1][b-1] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		int a; char c;
		cin >> a >> c;

		d.emplace(a, c);
	}

	s.emplace(0, 0); //뱀의 초기 위치
	int idx = 0; //오른쪽을 향해서 먼저 간다
	while (1) {
		res++;
		pair<int, int> back = s.back();
		pair<int, int> head = { back.first + dy[idx], back.second + dx[idx] };

		//몸통이나 (벽)에 부딪히는 경우 
		if ((head.first < 0 || head.first >= n || head.second < 0 || head.second >= n) || visited[head.first][head.second]) {
			break;
		}

		visited[head.first][head.second] = true;
		s.push(head);

		//사과가 있는 경우
		if (arr[head.first][head.second])
			arr[head.first][head.second] = 0;
		//사과가 없는 경우
		else {
			pair<int, int> tail = s.front();
			visited[tail.first][tail.second] = 0;
			s.pop();
		}

		//방향 전환
		if (d.size() && d.front().first == res) {
			if (d.front().second == 'L') idx = (idx + 3) % 4;
			else idx = (idx + 1) % 4;
			d.pop();
		}
	}
	cout << res;
	return 0;
}