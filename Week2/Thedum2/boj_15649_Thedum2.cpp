#include <iostream>
using namespace std;

int nm_array[9];
bool nm_isvisit[9];

void N_and_M(int number,int digit,int now) {

	//만약 현재 호출한 횟수가 출력할 자릿수보다 많다면
	if (now > digit) {
		//입력받은 자릿수만큼까지에 저장된 배열을 출력한다.
		for (int i = 1; i <= digit; i++)
			cout << nm_array[i] << " ";
		cout << "\n";
		return;
	}

	//아직 자릿수가 다 채워지지 않은 경우이다
	//number까지의 숫자 모두를 포함해야 한다
	for (int i = 1; i <= number; i++){
		//중복을 허용하지 않기 때문에 방문되지 않은 경우만 허용
		if (!nm_isvisit[i]) {
			nm_array[now] = i;//현재 자릿수를 저장
			nm_isvisit[i] = true;//방문 처리
			N_and_M(number, digit, now + 1);//다음 경우의 수 탐색
			nm_isvisit[i] = false;//다음 경우의 수를 위해 현재 경우의 수가 끝났다면,방문 취소 처리
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	N_and_M(N, M, 1);//1번부터 시작
}