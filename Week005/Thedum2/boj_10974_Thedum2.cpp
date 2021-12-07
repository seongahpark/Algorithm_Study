#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
bool visit[9];

void permutation(int number, int start)
{
	//마지막이라면 출력하고 종료
	if (start == number + 1){
		for (int i = 1; i <= number; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	//백트래킹 기법을 이용
	for (int i = 1; i <= number; i++){
		if (visit[i] == false) {
			arr[start] = i;
			visit[i] = true;
			permutation(number, start + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	permutation(n, 1);
}