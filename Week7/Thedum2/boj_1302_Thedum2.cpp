#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> BestSeller;
int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0);

	int cnt;
	string cmd;

	cin >> cnt;
	for (int i = 0; i < cnt; i++){
		cin >> cmd;
		if (BestSeller.find(cmd) == BestSeller.end())
			BestSeller.insert({ cmd ,1 });
		else
			++BestSeller[cmd];
	}

	string result;
	int BScnt = 0;
	for (auto A : BestSeller) {
		if (BScnt < A.second) {
			BScnt = A.second;
			result = A.first;
		}
		else if (BScnt == A.second) {
			if (result.compare(A.first) > 0) {
				BScnt = A.second;
				result = A.first;
			}
		}
	}

	cout << result;
}