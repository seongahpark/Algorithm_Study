#include <iostream>
#include <vector>
using namespace std;

vector<long long> pp;

long long pibo(int n)
{
	if (n < pp.size())
		return pp[n];
	else {
		pp.push_back(pibo(n - 1) + pibo(n - 2));
		return pibo(n - 1) + pibo(n - 2);
	}
}
int main()
{
	pp.push_back(0);
	pp.push_back(1);

	int T;
	cin >> T;

	int number;
	for (int i = 0; i < T; i++) {
		cin >> number;
		if (number == 0)
			cout << "1 0" << "\n";
		else if (number == 1)
			cout << "0 1" << "\n";
		else
			cout << pibo(number - 1) << " " << pibo(number) << "\n";
	}
}