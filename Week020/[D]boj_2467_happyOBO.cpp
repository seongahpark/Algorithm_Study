#include <bits/stdc++.h>

using namespace std;

void solution(int N, vector<int>& numbers);
pair<int, int> binarySearch(int number, int startIdx, int endIdx, vector<int>& numbers);

int main() {
	int N;
	cin >> N;
	vector<int> numbers(N);
	for (int i = 0; i < N; i++) cin >> numbers[i];

	solution(N, numbers);

}


void solution(int N,  vector<int>& numbers) 
{

	pair<int, int> result;
	int sum = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		pair<int, int> data = binarySearch(numbers[i], i+1, N -1, numbers);
		if (abs(data.first) < abs(sum))
		{
			result = { numbers[i], data.second };
			sum = data.first;
		}
	}

	cout << result.first << " " << result.second;
}

// first : 섞었을때 값, second : 택한 용액
pair<int, int> binarySearch(int number, int startIdx, int endIdx, vector<int>& numbers)
{
	int midIdx = (startIdx + endIdx) / 2;

	pair<int, int> result = { INT_MAX, -1 };

	while (startIdx <= endIdx)
	{
		int sum = number + numbers[midIdx];

		if (abs(sum) < abs(result.first)) result = { sum, numbers[midIdx] };

		if (sum == 0) break;
		else if (sum < 0) startIdx = midIdx + 1;
		else  endIdx = midIdx - 1;
		midIdx = (startIdx + endIdx) / 2;
	}

	return result;
}