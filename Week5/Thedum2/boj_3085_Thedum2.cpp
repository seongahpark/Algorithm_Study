#include <iostream>
#include <vector>
#include <string>

using namespace std;

int candyresult(vector<string> candy,int s)
{
	int columnresult = 1;
	int middleresult = 1;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s-1; j++) {
			if (candy[i][j] == candy[i][j + 1]) {
				middleresult++;
				if (middleresult > columnresult) {
					columnresult = middleresult;
				}
			}
			else{
				middleresult = 1;
			}
		}
		middleresult = 1;
	}

	int rowresult = 1;
	middleresult = 1;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s - 1; j++) {
			if (candy[j][i] == candy[j + 1][i]) {
				middleresult++;
				if (middleresult > rowresult)
					rowresult = middleresult;
			}
			else{
				middleresult = 1;
			}
		}
		middleresult = 1;
	}

	return max(columnresult,rowresult);
}
int main()
{

	int N;
	cin >> N;
	vector<string> Bomboni;
	string cmd;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		Bomboni.push_back(cmd);
	}

	int colanswer=0;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (Bomboni[i][j] != Bomboni[i][j + 1]) {
				swap(Bomboni[i][j], Bomboni[i][j + 1]);
				int c = candyresult(Bomboni, N);
				if (c > colanswer)
					colanswer = c;
					swap(Bomboni[i][j], Bomboni[i][j + 1]);
			}
		}
	}

	int rowanswer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (Bomboni[j][i] != Bomboni[j + 1][i]) {
				swap(Bomboni[j][i], Bomboni[j + 1][i]);
				int r = candyresult(Bomboni, N);
				if (r > rowanswer)
					rowanswer = r;
				swap(Bomboni[j][i], Bomboni[j + 1][i]);
			}
		}
	}
	cout << max(colanswer, rowanswer) << endl;
}