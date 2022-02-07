#include <iostream>
#include <map>

using namespace std;

map<int, int> NumberCard;
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0);

	int cnt, cmd;

	cin >> cnt;
	for (int i = 0; i < cnt; i++){
		cin >> cmd;
		if (NumberCard.find(cmd) == NumberCard.end())
			NumberCard.insert({ cmd ,1 });
		else
			++NumberCard[cmd];
	}

	cin >> cnt;
	for (int j = 0; j < cnt; j++){
		cin >> cmd;
		cout << NumberCard[cmd] << " ";
	}
}