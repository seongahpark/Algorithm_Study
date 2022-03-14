#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

const int MAX = INT_MAX;
int n;
int num[12], oper[4];
int maxRes = -MAX, minRes = MAX;

void dfs(int plus, int minus, int multi, int div, int cnt, int sum) {
	if (cnt == n) //연산자를 모두 사용한 경우
	{
		maxRes = max(maxRes, sum);
		minRes = min(minRes, sum);

	}

	//모든 경우 고려
	//궁금한 점 plus-1 대신 --plus 이런식으로 해주고싶은데 적용이 안됨
	if (plus > 0) dfs(plus-1, minus, multi, div, cnt+1, sum + num[cnt]);
	if (minus > 0) dfs(plus, minus-1, multi, div, cnt + 1, sum - num[cnt]);
	if (multi > 0) dfs(plus, minus, multi-1, div, cnt + 1, sum * num[cnt]);
	if (div > 0) dfs(plus, minus, multi, div-1, cnt + 1, sum / num[cnt]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> oper[i];

	dfs(oper[0], oper[1], oper[2], oper[3], 1, num[0]);

	cout << maxRes << "\n" << minRes;
	
	return 0;
}