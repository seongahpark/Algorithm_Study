#include <iostream>
#include <vector>
using namespace std;

int Triangle[501][501] = { 0, };
int DPTriangle[501][501] = { 0, };

int main() {

	int Dpsize;
	cin >> Dpsize;

	int cmd;
	cin >> cmd;
	Triangle[1][1]=cmd;
	DPTriangle[1][1] = cmd;

	for (int i = 2; i <= Dpsize; i++){
		for (int j = 1; j <= i; j++) {
			cin >> Triangle[i][j];
			DPTriangle[i][j]= Triangle[i][j]+max(DPTriangle[i-1][j-1], DPTriangle[i-1][j]);
		}
	}

	int result=0;
	for (int i = 1; i <= Dpsize; i++)
		result = max(result, DPTriangle[Dpsize][i]);
	
	cout << result;
}