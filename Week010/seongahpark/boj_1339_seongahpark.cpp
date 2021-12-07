#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	int alpha[26] = { 0 }, res = 0;
	cin >> n;

	vector<string> v;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	// 단어를 1의자리부터 자릿수에 맞게 풀어줌
	for (int i = 0; i < v.size(); i++) {
		int pow = 1;
		for (int j = v[i].size() - 1; j >= 0; j--) {
			int val = v[i][j] - 'A';
			alpha[val] += pow;
			pow *= 10;
		}
	}


	sort(alpha, alpha + 26);

	//가장 큰값을 가지는 알파벳부터 9를 배당
	int num = 9;
	for (int i = 25; i >= 0; i--) {
		if (alpha[i] == 0) break;
		res += (alpha[i] * num);
		num--;
	}

	cout << res;
	return 0;
}