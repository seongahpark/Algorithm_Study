#include <bits/stdc++.h>

using namespace std;

void solution(int N);
void calcEratos(int N);
int partialSumCount(int N);

vector<int> primes;

int main() {
	int N;
	cin >> N;
	solution(N);
}


void solution(int N) 
{
	calcEratos(N);
	cout << partialSumCount(N);
}

void calcEratos(int N)
{
	if (N <= 1) return;

	vector<bool> numbers(N + 1, true);

	for (int i = 2; i * i <= N; i++)
	{
		if (numbers[i])
			for (int j = i * i; j <= N; j += i)
				numbers[j] = false;
	}

	for (int i = 2; i <= N; i++)
	{
		if (numbers[i]) primes.push_back(i);
	}

	return;
}


int partialSumCount(int N)
{
	int counter = 0;
	int startIdx = 0, endIdx = 0, sum = 0;

	while (true)
	{
		if (N <= sum)
			sum -= primes[startIdx++];
		else if (primes.size() <= endIdx)
			break;
		else
			sum += primes[endIdx++];

		if (sum == N)
			counter++;
	}
	return counter;
}