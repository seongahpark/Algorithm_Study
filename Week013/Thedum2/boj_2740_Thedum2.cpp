#include <iostream>
#include <vector>
using namespace std;

int Resultvec[101][101];
vector<short> Avec[101];
vector<short> Bvec[101];

int main() {

	int n1, m1,n2,m2;
	int num;
	cin >> n1 >> m1;
	for (int i = 0; i < n1; i++){
		for (int j = 0; j < m1; j++){
			cin >> num;
			Avec[i].push_back(num);
		}
	}

	cin >> n2 >> m2;
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < m2; j++) {
				cin >> num;
				Bvec[i].push_back(num);
		}
	}


	for (int i = 0; i < n1; i++) {
		for (int j = 0; j <m2; j++) {
			for (int k = 0; k < n2; k++) {
				int sum;
				Resultvec[i][j] += Avec[i][k] * Bvec[k][j];
			}
			cout << Resultvec[i][j] << " ";
		}
		cout << endl;
	}
}