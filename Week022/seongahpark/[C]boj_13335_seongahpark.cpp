#include <iostream>
#include <queue>
const int MAX = 1001;
using namespace std;

int n, w, l; // n Ʈ������, w ��������, l �ִ�����
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
		//while�� ���� ó���� �־��ָ� ���� Ʈ���� �ٷ� ���͹���
		//�ִ� ������ �Ѿ�� ���� �߻���
		q.push(arr[i]);
		curWeight += arr[i];
		res++;
	}
	//�������� ����� �ȵƱ� ����
	cout << res + w;
	return 0;
}