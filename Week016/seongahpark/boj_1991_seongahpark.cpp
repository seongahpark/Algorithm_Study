#include <iostream>
#include <vector>

using namespace std;

const int MAX = 27;

// 구조체로 트리 생성
struct node {
	char left;
	char right;
} v[MAX];

int n;
char root, l, r;

void Pre(char root) {
	// root - left - right
	if (root == '.') return;

	cout << root;
	Pre(v[root].left);
	Pre(v[root].right);
}

void In(char root) {
	// left - root - right
	if (root == '.') return;

	In(v[root].left);
	cout << root;
	In(v[root].right);
}

void Post(char root) {
	// left - right - root
	if (root == '.') return;

	Post(v[root].left);
	Post(v[root].right);
	cout << root;
}
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> root >> l >> r;
		v[root] = { l, r }; // root에 left와 right 값을 넣어줌
	}

	Pre('A');
	cout << "\n";

	In('A');
	cout << "\n";

	Post('A');

	return 0;
}