#include <bits/stdc++.h>

using namespace std;

void solution(int N, int K, vector<int>& numbers);

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> numbers(N);
	for (int i = 0; i < N; i++) cin >> numbers[i];

	solution(N, K, numbers);

}


void solution(int N, int K, vector<int>& numbers) 
{
	int result = accumulate(numbers.begin(), numbers.begin() + K, 0);
	int curr = result;
	for (int start = 0, end = K; end < N; start++,end++)
	{
		curr = curr - numbers[start] + numbers[end];
		result = max(result, curr);
	}
	cout << result;
}
