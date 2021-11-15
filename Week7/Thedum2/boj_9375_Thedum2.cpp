#include <iostream>
#include <map>

using namespace std;

int main() {
	
	int TestCase;
	cin >> TestCase;

	for (int i = 0; i < TestCase; i++){
		map<string, int> Fashion;
		int Count;
		string Name, Category;

		cin >> Count;
		for (int j = 0; j < Count; j++){
			cin >> Name >> Category;

			if (Fashion.find(Category) == Fashion.end())
				Fashion.insert({ Category ,1 });
			else
				++Fashion[Category];

		}

		int result = 1;
		for (auto cnt : Fashion) {
			result *= (cnt.second + 1);
		}

		cout << result - 1 << endl;

	}
}