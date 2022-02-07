#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> Numbersearcha;

int main()
{
	ios_base::sync_with_stdio(0);

	cin.tie(0); 

	int numa;
	cin >> numa;
	int cmd;
	for (int i = 0; i < numa; i++) {
		cin >> cmd;
		Numbersearcha.push_back(cmd);
	}

	sort(Numbersearcha.begin(), Numbersearcha.end());

	int numb;
	cin >> numb;
	for (int i = 0; i < numb; i++) {
		int cmd;
		cin >> cmd;
		int result = binary_search(Numbersearcha.begin(), Numbersearcha.end(), cmd);
		cout << result << "\n";
	}
}