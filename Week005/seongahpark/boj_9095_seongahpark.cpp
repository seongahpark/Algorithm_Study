#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int arr[11] = { 1, 2, 4, 0 };
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		
		for (int j = 3; j < tmp; j++) {
			arr[j] = arr[j - 3] + arr[j - 2] + arr[j - 1];
		}
		cout << arr[tmp - 1] << "\n";
	}

	return 0;
}