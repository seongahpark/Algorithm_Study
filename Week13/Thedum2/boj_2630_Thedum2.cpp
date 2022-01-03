#include <iostream>
#include <vector>
using namespace std;

int resultwhite=0, resultblue=0;
vector<bool> Paper[128];

void Search(int n, int a, int b) {
	int color = Paper[a][b];

	for (int i = a; i < a + n; i++) {
		for (int j = b; j < b + n; j++) {
			if (Paper[i][j] != color) {
				Search(n / 2, a, b);			//왼쪽 위
				Search(n / 2, a + n / 2, b);		//왼쪽 아래
				Search(n / 2, a, b + n / 2);		//오른쪽 위
				Search(n / 2, a + n / 2, b + n / 2);	//오른쪽 아래
				return;
			}
		}
	}
	if (color == 1) resultblue++;
	else resultwhite++;
}

int main()
{
	int n;
	cin >> n;

	bool b;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> b;
			Paper[i].push_back(b);
		}
	}
	Search(n, 0, 0);
	cout << resultwhite << "\n" << resultblue;
}