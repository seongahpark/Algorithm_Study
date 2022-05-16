#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int A, B, C;
vector<int> v;
bool visited[201][201][201];

struct bucket {
	int a, b, c;
};

// 두 가지 경우 고려
// 1. 비우는 물통 양 + 채우는 물통 양 > 채우는 물통 크기
// 2. 비우는 물통 양 + 채우는 물통 양 <= 채우는 물통 크기
void bfs() {
	queue<bucket> q;
	q.push({ 0, 0, C });

	while (!q.empty()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		if (visited[a][b][c]) continue;
		visited[a][b][c] = true;
		if (a == 0) v.push_back(c);

		// a->b
		if (a + b > B) q.push({ a + b - B, B, c });
		else q.push({ 0, a + b, c });

		// a->c
		if (a + c > C) q.push({ a + c - C, b, C });
		else q.push({ 0, b, a + c });

		// b->a
		if (b + a > A) q.push({ A, b + a - A, c });
		else q.push({ b + a, 0, c });

		// b->c
		if (b + c > C) q.push({ a, b + c - C, C });
		else q.push({ a, 0, b + c });

		// c->a
		if (c + a > A) q.push({ A, b, c + a - A });
		else q.push({c + a, b, 0});

		// c->b
		if (c + b > B) q.push({ a, B, c + b - B });
		else q.push({ a, c + b, 0 });
	}
}

int main() {
	cin >> A >> B >> C;
	bfs();
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	return 0;
}