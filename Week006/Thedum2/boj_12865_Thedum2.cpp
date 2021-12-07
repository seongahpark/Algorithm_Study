#include <iostream>
#include <vector>

using namespace std;

int W[101], V[101], Bag_W_V[101][100001];

int main() {

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= W[i])    Bag_W_V[i][j] = max(Bag_W_V[i - 1][j], Bag_W_V[i - 1][j - W[i]] + V[i]);
			else Bag_W_V[i][j] = Bag_W_V[i - 1][j];
		}
	}
	cout << Bag_W_V[N][K] << endl;

}