#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> //sqrt 사용
using namespace std;

const int MAX = 4000000;

int n, sum;
int arr[MAX+1];
vector<int> p; //prime_num 저장
vector<int> v; 
int main() {
	cin >> n;
	v.push_back(0); //기본값

	// 에라토스테네스의 체 - 소수 구하는 알고리즘
	for (int i = 2; i < sqrt(MAX); i++) {
		for (int j = i * 2; j <= MAX; j += i) {
			arr[j] = 1; //소수 X
		}
	}
	for (int i = 2; i <= MAX; i++) {
		if (!arr[i]) { // 소수들의 구간합
			sum += i;
			v.push_back(sum);
		}
	}

	// 투 포인터
	int res = 0, left = 0, right = 0;
	while (left <= right && right < v.size()) {
		//오른쪽으로 계속 이동하면서 n을 만족하는 구간합 개수 셈
		if (v[right] - v[left] > n) left++;
		else if (v[right] - v[left] < n) right++;
		else {
			res++;
			right++;
		}
	}
	cout << res;
	return 0;
}
