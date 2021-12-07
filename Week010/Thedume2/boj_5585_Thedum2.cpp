#include <iostream>

using namespace std;

int main() {
	int price;
	cin >> price;
	int money=1000-price;
	int coin[6] = { 500,100,50,10,5,1 };
	int result = 0;
	for (int i = 0; i < 6; i++){
		result += (money / coin[i]);
		money -= (money / coin[i]) * coin[i];
	}
	cout << result;
}