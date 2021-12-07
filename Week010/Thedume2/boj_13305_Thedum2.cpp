#include <iostream>

using namespace std;

long long dist[100001];
long long price[100001];
long long greedy=1000000000;

int main() {
	int repeat;
	cin >> repeat;
	for (int i = 0; i < repeat - 1; i++)
		cin >> dist[i];
	for (int i = 0; i < repeat; i++)
		cin >> price[i];
	int sum=0;
	for (int i = 0; i < repeat - 1; i++) {
		greedy = price[i] < greedy ? price[i] : greedy;
		sum += greedy * dist[i];
	}
	cout << sum;
}