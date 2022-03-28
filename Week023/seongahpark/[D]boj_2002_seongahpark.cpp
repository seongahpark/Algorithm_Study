#include <iostream>
#include <map>
using namespace std;

map<string, int> m;
int fin[1001]; //���� ������ ��ȣ�� ��� ���� �迭

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, res = 0;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++) { // �� �Է�
		cin >> str;
		m[str] = i;
	}

	for(int i = 0; i < n; i++) { // ���� �Է�
		cin >> str;
		int tmp = m[str];
		fin[i] = tmp;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (fin[i] > fin[j]) {
				res++;
				break;
			}
		}
	}

	cout << res;
	return 0;
}