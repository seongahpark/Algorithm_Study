#include <iostream>
#include <queue>
#include<string>

using namespace std;

int main()
{
	queue <int> yosepus;
	string result = "<";
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		yosepus.push(i);

	while (!yosepus.empty()) {

		for (int j = 0; j < k - 1; j++) {
			yosepus.push(yosepus.front());
			yosepus.pop();
		}

		result += to_string(yosepus.front())+", ";
		yosepus.pop();
	}
	for (int i = 0; i < result.length() - 2; i++)
		cout << result[i];

	cout << ">";
}
